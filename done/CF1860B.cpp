// https://codeforces.com/contest/1860/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, m, k, a1, ak, tmp, n, ov;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> m >> k >> a1 >> ak;

        tmp = m / k;
        tmp = min(tmp, ak);
        m -= tmp * k;

        n = 0;
        if (m > a1) {
            ov = m - a1;
            tmp = ov / k;
            if (ov % k) ++tmp;
            if (tmp * k > m) --tmp;
            n += tmp;
            m -= tmp * k;
        }
        m -= a1;

        if (m > 0) n += m;

        cout << n << '\n';
    }

    return 0;
}
