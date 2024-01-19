// https://codeforces.com/problemset/problem/266/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, t;
        string q;

        cin >> n >> t;
        cin >> q;

        for (int i = 0; i < t; i++) {
                for (int j = 0; j < n - 1; j++) {
                        if (q[j] == 'B' && q[j + 1] == 'G') {
                                q[j] = 'G';
                                q[j + 1] = 'B';
                                j++;
                        }
                }
        }

        cout << q << '\n';
        
        return 0;
}
