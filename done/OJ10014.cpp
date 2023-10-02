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

        double a0, af;
        cin >> a0;
        cin >> af;

        double c[n];

        for (int i = 0; i < n; ++i) cin >> c[i];

        double res = n * a0 + af;

        for (int i = 1; i <= n; ++i) res -= i * 2 * c[n - i];

        res /= (n + 1);

        cout << fixed << setprecision(2) << res << '\n';

        if (t) cout << '\n';
    }

    return 0;
}
