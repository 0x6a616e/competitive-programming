// https://codeforces.com/problemset/problem/1872/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        double d;

        cin >> a >> b >> c;

        d = abs(a - b) / 2.0;

        cout << ceil(d / c) << '\n';
    }

    return 0;
}
