#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// ** The code in main() was provided.  The solve function below
// was empty and needed to be completed to enable the function
// to run properly.
// **
void solve(vector<int> low, vector<int> high, vector<int> close) 
{
    int gapUp = 0;
    int gapDown = 0;

    for (int i = 0; i < low.size() - 1; i++)
    {
        if (close[i] < low[i + 1])
            gapUp += 1;
        if (close[i] > high[i + 1])
            gapDown += 1;
    }

    cout << gapUp << " " << gapDown;

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string low_temp_temp;
    getline(cin, low_temp_temp);

    vector<string> low_temp = split(rtrim(low_temp_temp));

    vector<int> low(n);

    for (int i = 0; i < n; i++) {
        int low_item = stoi(low_temp[i]);

        low[i] = low_item;
    }

    string high_temp_temp;
    getline(cin, high_temp_temp);

    vector<string> high_temp = split(rtrim(high_temp_temp));

    vector<int> high(n);

    for (int i = 0; i < n; i++) {
        int high_item = stoi(high_temp[i]);

        high[i] = high_item;
    }

    string close_temp_temp;
    getline(cin, close_temp_temp);

    vector<string> close_temp = split(rtrim(close_temp_temp));

    vector<int> close(n);

    for (int i = 0; i < n; i++) {
        int close_item = stoi(close_temp[i]);

        close[i] = close_item;
    }

    solve(low, high, close);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
