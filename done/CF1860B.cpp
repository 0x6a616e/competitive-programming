#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int m, k, a1, ak;

        cin >> m >> k >> a1 >> ak;

        while (ak && m >= k) {
            --ak;
            m -= k;
        }
        int n = 0;
        while (m > a1 && m >= k) {
            ++n;
            m -= k;
        }
        m -= a1;

        if (m > 0) n += m;

        cout << n << '\n';
    }

    return 0;
}
