# This program is a guessing game.  It uses a random number generator, and 
# gives hints when the player is close.  The range is 1 to 1000, and the clue
# is given when the player is within 10 points of the chosen number.


# Import the random module

import random

# Function with hint calculator

def hint(target_number, target_guess):
	if target_number - target_guess > 10:
		print('low')
	elif target_number - target_guess <= 10 and target_number - target_guess > 0:
		print('warm, but a bit too low')
	elif target_guess - target_number <= 10 and target_guess - target_number > 0:
		print('warm, but a bit too high')
	elif target_guess - target_number > 10:
		print('high')

# Create loop control

again = "y"

guess_count = 1

m1 = "It took you "
m2 = " guesses"
m3 = " guess.. incredible!"

# Define the game

while again == "y" or again == "Y":

	target_number = random.randint(1, 1000)
	print(target_number)
	target_guess = int(input('Guess any number from 1 to 1000: '))

	while target_guess != target_number:
		guess_count += 1
		hint(target_number, target_guess)
		target_guess = int(input('Guess again: '))

	print('We have a winner!!!')
	if guess_count == 1:
		print m1, guess_count, m3
	else:
		print m1, guess_count, m2
