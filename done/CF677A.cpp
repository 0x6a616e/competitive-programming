// https://codeforces.com/problemset/problem/677/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, h, ai, t;

        cin >> n >> h;

        t = n;

        for (int i = 0; i < n; i++) {
                cin >> ai;
                if (ai > h) {
                        t++;
                }
        }

        cout << t << '\n';
        
        return 0;
}
