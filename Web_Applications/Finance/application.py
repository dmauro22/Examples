import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
from time import strftime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():

    myStocks = db.execute("SELECT * FROM portfolio WHERE id=:id ORDER BY symbol", id=session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
    cash = (cash[0]['cash'])
    prices = []
    sVal = 0
    for stk in myStocks:
        quote = lookup(stk["symbol"])
        stk.update(quote)
        totalValue = quote['price'] * stk['shares']
        sVal += (totalValue) # float('%.2f'%(totalValue))
        totalValue = usd(totalValue)
        stk.update({'Total': totalValue})
        stk['price'] = usd(stk['price'])

    sVal += cash
    sVal = usd(sVal)
    cash = usd(cash)
    return render_template("index.html", myStocks=myStocks, sVals=sVal, cash=cash)

    """Show portfolio of stocks"""
    return apology("Sorry, you are logged in")


@app.route("/addcash", methods=["GET", "POST"])
@login_required
def addcash():
    if request.method == "POST":
        money = float(request.form.get("cash"))
        
        if money <= 0:
            return apology("Must be more than zero...")
        else:
            db.execute("UPDATE users SET cash=cash+:money WHERE id = :id", money=money, id=session["user_id"])
            return redirect("/")

    else:
        return render_template("addcash.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    if request.method == "POST":
        stock = request.form.get("symbol")
        stock = stock.upper()
        amount = request.form.get("shares")

        if not amount.isdigit():
            return apology("Must be an integer", 400)

        amount = int(amount)

        quote = lookup(stock)
        timestamp = strftime("%c, %Z")

        if not quote:
            return apology("Come on...")

        if amount <= 0:
            return apology("You know better than that")

        price = quote['price']

        totalCost = (float(amount) * quote['price'])

        cashAvail = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

        cashAvail = (cashAvail[0]["cash"])

        if (cashAvail - totalCost) < 0:
            return apology("Insufficient funds :( :( :(")

        else:
            #totalCost = usd(totalCost)
            db.execute("UPDATE users SET cash=cash-:cost WHERE id=:id", cost=totalCost, id=session["user_id"])

            result = db.execute("SELECT * FROM portfolio WHERE id=:id AND symbol=:stock", id=session["user_id"], stock=stock)

            if result: # already own this stock, updating existing record
                result = db.execute("UPDATE portfolio SET shares=shares+:amount WHERE id=:id AND symbol=:symbol", amount=amount, id=session["user_id"], symbol=stock)

            else: # Do not currently own the stock, creating new record
                db.execute("")
                result = db.execute("INSERT INTO portfolio (id, symbol, shares) VALUES(:id, :symbol, :shares)", id=session["user_id"], symbol=stock, shares=amount)

            bs = "buy"
            # Update history log
            db.execute("INSERT INTO history (user_id, buy_sell, symbol, shares, price, timestamp) \
            VALUES(:id, :bs, :symbol, :shares, :price, :timestamp)",
            id=session["user_id"], bs=bs, symbol=stock, shares=amount, price=price, timestamp=timestamp)


    else:
        return render_template("buy.html")
    """Buy shares of stock"""

    return redirect("/")
    return apology("We done bought the dadgum thang")


@app.route("/history")
@login_required
def history():

    past = db.execute("SELECT * FROM history WHERE user_id=:id", id=session["user_id"])
    #print(past)

    for item in past:
        total = (item['price'] * item['shares'])
        item['price'] = (item['price'])
        item.update({'total_cost': total})

    if request.method == "POST":
        render_template("history.html", past=past)

    else:
        return render_template("history.html", past=past)

    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():

    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if quote:
            quote["price"] = usd(quote["price"])
            #print(quote)
            return render_template("display.html", quote=quote)
        else:
            return apology("Enter a valid stock, bruv", 400)



    else:
        return render_template("quote.html")
    """Get stock quote."""

@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide password confirmation", 400)

        # Ensure password and confirmation match
        elif not (request.form.get("password") == request.form.get("confirmation")):
            return apology("password and confirmation must match", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Check to see if username exists
        if len(rows) != 0:
            return apology("Username already taken", 400)

        else:
            passhash = generate_password_hash(request.form.get("password"))
            username = request.form.get("username")
            result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :passhash)",
                                username = username, passhash = passhash)
            if not result:
                return apology("Sad face, we encountered a database error", 411)

            # Redirect user to home page
            else:
                rows = db.execute("SELECT * FROM users WHERE username = :username",
                                username=request.form.get("username"))
                session["user_id"] = rows[0]["id"]
                return redirect("/")

            return apology("Unknown error", 466)

    else:
        return render_template("register.html")
    #else:
    #    return apology("We made it this far", 402)

    """Register user"""
    return apology("Didn't like it")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():


    if request.method == "POST":
        myStocks = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])

        stock = request.form.get("symbol")
        amount = int(request.form.get("shares"))

        if amount <= 0:
            return apology("Come on now")

        curShares = db.execute("SELECT shares FROM portfolio WHERE id=:id AND symbol=:stock", id=session["user_id"], stock=stock)

        curShares = curShares[0]['shares']

        if curShares < amount:
            return apology("You don't have enough shares")

        quote = lookup(stock)
        timestamp = strftime("%c, %Z")

        if not quote:
            return apology("Not a valid selection")
        quote = lookup(stock)
        price = quote['price']
        cost = price * amount

        if curShares == amount:
            db.execute("DELETE from portfolio WHERE id=:id AND symbol=:stock", id=session["user_id"], stock=stock)
        else:
            db.execute("UPDATE portfolio SET shares=shares-:amount WHERE id=:id AND symbol=:stock", amount=amount, id=session["user_id"], stock=stock)

        db.execute("UPDATE users SET cash=cash+:cost WHERE id=:id", cost=cost, id=session["user_id"])


        bs = "sell"
        # Update history log
        db.execute("INSERT INTO history (user_id, buy_sell, symbol, shares, price, timestamp) \
        VALUES(:id, :bs, :symbol, :shares, :price, :timestamp)",
        id=session["user_id"], bs=bs, symbol=stock, shares=amount, price=price, timestamp=timestamp)


        return redirect("/")
        return apology("You done sold them varmints")

    else:
        myStocks = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])

        return render_template("sell.html", myStocks=myStocks)
        #print("This worked")

    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
