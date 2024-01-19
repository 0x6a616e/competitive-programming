// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int sol = 1;
    int best = 0;
    char lastChar = '.';

    for (char &c : s) {
        if (c == lastChar) {
            ++sol;
        } else {
            best = max(best, sol);
            sol = 1;
        }
        lastChar = c;
    }
    best = max(best, sol);

    cout << best << endl;

    return 0;
}
