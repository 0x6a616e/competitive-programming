// https://codeforces.com/problemset/problem/116/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, maximo = 0, e, s, a;

        cin >> n;

        for (int i = 0; i < n; i++) {
                cin >> s >> e;
                a -= s;
                a += e;
                maximo = max(maximo, a);
        }

        cout << maximo << '\n';
        
        return 0;
}
