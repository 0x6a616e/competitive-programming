// https://codeforces.com/problemset/problem/1894/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << s[n - 1] << '\n';
    }

    return 0;
}
