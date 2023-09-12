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

        long long ds[n];
        for (int i = 0; i < n; ++i) cin >> ds[i];

        long long sol = ds[n - 1] * -1LL;
        long long d;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) {
                d = ds[j] - ds[i];
                if (d < 0) sol += d;
            }

        if (n == 1 || n == 2)
            cout << "0\n";
        else
            cout << sol << '\n';
    }

    return 0;
}
