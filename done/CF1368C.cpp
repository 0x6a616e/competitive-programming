#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << 3 * n + 4 << '\n';

    int x = 0;
    int y = 0;
    int contador = 0;

    cout << x << ' ' << y << '\n';
    while (contador < n + 1) {
        cout << x + 1 << ' ' << y << '\n';
        cout << x << ' ' << y + 1 << '\n';
        ++x;
        ++y;
        cout << x << ' ' << y << '\n';
        ++contador;
    }

    return 0;
}
