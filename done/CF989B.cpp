// https://codeforces.com/problemset/problem/989/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    bool sol = false;

    for (int i = p; i < n && !sol; ++i) {
        if (s[i] == '.') {
            sol = true;
            if (s[i - p] == '.') {
                s[i - p] = '0';
                s[i] = '1';
            } else {
                s[i] = s[i - p] == '0' ? '1' : '0';
            }
        } else {
            if (s[i - p] != '.' && s[i] != s[i - p]) sol = true;
        }
    }

    for (int i = 0; i + p < n && !sol; ++i) {
        if (s[i] == '.') {
            sol = true;
            if (s[i + p] == '.') {
                s[i + p] = '0';
                s[i] = '1';
            } else {
                s[i] = s[i + p] == '0' ? '1' : '0';
            }
        } else {
            if (s[i + p] != '.' && s[i] != s[i + p]) sol = true;
        }
    }

    if (sol) {
        for (char &c : s)
            if (c == '.')
                cout << '0';
            else
                cout << c;
        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
