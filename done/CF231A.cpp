// https://codeforces.com/problemset/problem/231/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, a, b, c, acum = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
                cin >> a >> b >> c;
                if (a + b + c >= 2)
                        acum++;
        }

        cout << acum << '\n';
        
        return 0;
}
