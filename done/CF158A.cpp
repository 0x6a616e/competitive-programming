// https://codeforces.com/problemset/problem/158/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, k, ni, c = 0;
        vector<int> ns;

        cin >> n >> k;

        ns.resize(n);

        for (int i = 0; i < n; i++) {
                cin >> ns[i];
        }

        for (int i = 0; i < n; i++) {
                if (ns[i] > 0 && ns[i] >= ns[k - 1]) {
                        c++;
                }
        }

        cout << c << '\n';
        
        return 0;
}
