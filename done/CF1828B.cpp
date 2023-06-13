// https://codeforces.com/problemset/problem/1828/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t, n, p, mcd;

        cin >> t;

        for (int i = 0; i < t; i++) {
                mcd = 0;
                cin >> n;
                for (int j = 1; j <= n; j++) {
                        cin >> p;
                        mcd = gcd(mcd, abs(p - j));
                }

                cout << mcd << '\n';
        }
        
        return 0;
}
