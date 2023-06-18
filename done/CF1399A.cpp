// https://codeforces.com/contest/1399/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        while (t--) {
                int n;

                cin >> n;

                vector<int> a(n);

                for (int i = 0; i < n; i++) {
                        cin >> a[i];
                }

                sort(a.begin(), a.end());

                bool posible = false;
                if (n == 1) {
                        cout << "YES\n";
                } else {
                        posible = true;
                        for (int i = 0; i < n - 1 && posible; i++) {
                                if (abs(a[i] - a[i + 1]) > 1) {
                                        posible = false;
                                }
                        }

                        if (posible) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                }
        }
        
        return 0;
}
