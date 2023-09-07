#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        long long n, x, y, sol;
        cin >> n >> x >> y;
        sol = 0;

        long long x_multiplos = n / x;
        long long y_multiplos = n / y;
        long long interseccion = n / (x * y);

        x_multiplos -= interseccion;
        y_multiplos -= interseccion;

        if (x % y == 0) x_multiplos = 0;
        if (y % x == 0) y_multiplos = 0;

        if (x_multiplos > 0) {
            long long inicia_x = n - x_multiplos + 1;
            sol += x_multiplos * inicia_x;
            sol += ((n - inicia_x) * (n - inicia_x + 1)) / 2;
        }

        long long termina_y = 1 + y_multiplos - 1;
        sol -= (termina_y * (termina_y + 1)) / 2;

        cout << sol << '\n';
    }

    return 0;
}
