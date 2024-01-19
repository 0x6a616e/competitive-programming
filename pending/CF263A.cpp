// https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int x, y, n;

        for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++) {
                        cin >> n;
                        if (n == 1) {
                                x = j;
                                y = i;
                        }
                }
        }

        cout << abs(3 - x) + abs(3 - y) << '\n';

        return 0;
}
