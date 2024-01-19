// https://codeforces.com/problemset/problem/467/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, p, q, c = 0;

        cin >> n;

        while (n--) {
                cin >> p >> q;
                if (q - p >= 2) {
                        c++;
                }
        }

        cout << c << endl;
        
        return 0;
}
