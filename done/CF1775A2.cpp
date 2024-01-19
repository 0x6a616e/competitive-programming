// https://codeforces.com/problemset/problem/1775/A2

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s[0] == 'a' && s[1] == 'b') {
            cout << s[0] << ' ' << s.substr(1, s.size() - 2) << ' ' << s.back()
                 << '\n';
        } else {
            cout << s[0] << ' ' << s[1] << ' ' << s.substr(2) << '\n';
        }
    }

    return 0;
}
