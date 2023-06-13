// https://codeforces.com/problemset/problem/1829/D

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t, n, m, intento;
        bool posible;

        cin >> t;

        for (int i = 0; i < t; i++) {
                cin >> n >> m;
                posible = false;
                queue<int> intentos;

                if (n == m) {
                        posible = true;
                } else {
                        intentos.push(n);
                }
                

                while (!intentos.empty() && !posible) {
                        intento = intentos.front();
                        intentos.pop();
                        if (intento > m && intento % 3 == 0) {
                                if (m % (intento / 3) == 0) {
                                        posible = true;
                                }
                                intentos.push(intento / 3);
                                intentos.push(2 * intento / 3);
                        }
                }

                if (posible) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
        }
        
        return 0;
}
