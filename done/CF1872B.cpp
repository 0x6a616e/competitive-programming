// https://codeforces.com/problemset/problem/1872/B

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
        int final = 200 * 200;
        for (int i = 0; i < n; ++i) {
            int d, s;
            cin >> d >> s;
            final = min(final, d + (int)ceil(s / 2.0) - 1);
        }

        cout << final << '\n';
    }

    return 0;
}
