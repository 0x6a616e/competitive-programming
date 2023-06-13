// https://codeforces.com/problemset/problem/1833/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t, n;
        long long k;

        cin >> t;

        for (int i = 0; i < t; i++) {
                cin >> n >> k;
                vector<long long> a_orig(n), a_ord(n), b(n);
                map<long long, queue<long long>> mapa;

                for (int j = 0; j < n; j++) {
                        cin >> a_orig[j];
                        a_ord[j] = a_orig[j];
                }

                for (int j = 0; j < n; j++) {
                        cin >> b[j];
                }

                sort(a_ord.begin(), a_ord.end());
                sort(b.begin(), b.end());

                for (int j = 0; j < n; j++) {
                        mapa[a_ord[j]].push(b[j]);
                }

                for (int j = 0; j < n; j++) {
                        cout << mapa[a_orig[j]].front() << ' ';
                        mapa[a_orig[j]].pop();
                }
                cout << '\n';
        }
        
        return 0;
}
