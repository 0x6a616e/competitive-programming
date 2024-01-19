// https://codeforces.com/problemset/problem/791/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int a, b, c = 0;

        cin >> a >> b;

        while (a <= b) {
                c++;
                a *= 3;
                b *= 2;
        }

        cout << c << '\n';
        
        return 0;
}
