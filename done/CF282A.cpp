// https://codeforces.com/problemset/problem/282/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, x = 0;
        string op;

        cin >> n;

        while (n--) {
                cin >> op;
                if (op[1] == '+') {
                        x++;
                } else {
                        x--;
                }
        }

        cout << x << '\n';
        
        return 0;
}
