// https://codeforces.com/problemset/problem/546/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int k, w;
        long long n, x = 0;

        cin >> k >> n >> w;

        for (int i = 1; i <= w; i++) {
                x += k * i;
        }

        cout << ((x - n) < 0 ? 0 : (x - n)) << '\n';
        
        return 0;
}
