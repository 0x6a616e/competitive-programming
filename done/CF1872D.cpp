#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

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
        long long interseccion = n / lcm(x, y);

        x_multiplos -= interseccion;
        y_multiplos -= interseccion;

        if (x_multiplos) {
            long long termina_x = x_multiplos - 1;
            sol += n * x_multiplos;
            sol -= (termina_x * (termina_x + 1)) / 2;
        }

        long long termina_y = y_multiplos;
        sol -= (termina_y * (termina_y + 1)) / 2;

        cout << sol << '\n';
    }

    return 0;
}
