// https://codeforces.com/problemset/problem/617/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int x;

        cin >> x;

        if (x % 5) {
                cout << x / 5 + 1;
        } else {
                cout << x / 5;
        }
        cout << '\n';
        
        return 0;
}
