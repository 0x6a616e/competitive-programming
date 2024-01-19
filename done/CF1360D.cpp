// https://codeforces.com/problemset/problem/1360/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    int n, k, x, y;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        int mejor = n;
        for (int j = 1; j * j <= n; ++j) {
            if (n % j == 0) {
                x = j;
                y = n / j;
                if (y <= k) mejor = min(mejor, x);
                if (x <= k) mejor = min(mejor, y);
            }
        }
        cout << mejor << '\n';
    }

    return 0;
}
