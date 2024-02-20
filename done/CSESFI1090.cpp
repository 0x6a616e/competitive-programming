// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p, p + n);
    int l = 0;
    int r = n - 1;
    int sol = 0;
    while (l <= r) {
        if (l != r && p[l] + p[r] <= x) {
            ++l;
            --r;
            ++sol;
        } else {
            --r;
            ++sol;
        }
    }

    cout << sol << '\n';

    return 0;
}
