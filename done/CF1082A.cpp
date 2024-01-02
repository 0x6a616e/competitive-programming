#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) {
    long long res = (long long)a + b - 1;
    res /= b;

    return (int)res;
}

int solve(int n, int x, int y, int d) {
    if (y == 1) return ceil(x - 1, d);

    if (y == n) return ceil(n - x, d);

    int diff = abs(y - x);
    if (diff % d == 0) return diff / d;

    int sol1 = 0;
    int sol2 = 0;

    if ((y - 1) % d == 0) sol1 = ceil(x - 1, d) + ((y - 1) / d);

    if ((n - y) % d == 0) sol2 = ceil(n - x, d) + ((n - y) / d);

    if (sol1 && sol2) return min(sol1, sol2);

    if (sol1 || sol2) return sol1 | sol2;

    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y, d;
        cin >> n >> x >> y >> d;

        cout << solve(n, x, y, d) << '\n';
    }

    return 0;
}
