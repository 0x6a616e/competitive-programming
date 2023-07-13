#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &memo, vector<int> &fila, int &columnas) {
    memo[columnas - 1] = fila[columnas - 1];

    if (columnas > 1) {
        memo[columnas - 2] = max(fila[columnas - 2], fila[columnas - 1]);
    }

    for (int columna = columnas - 3; columna >= 0; --columna) {
        memo[columna] =
            max(fila[columna] + memo[columna + 2], memo[columna + 1]);
    }

    return memo[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int filas, columnas;
    vector<int> lectura_fila(100001), maximos(100001), memo(100001);

    while (cin >> filas >> columnas && (filas || columnas)) {
        for (int fila = 0; fila < filas; ++fila) {
            for (int columna = 0; columna < columnas; ++columna) {
                cin >> lectura_fila[columna];
            }
            maximos[fila] = solve(memo, lectura_fila, columnas);
        }
        cout << solve(memo, maximos, filas) << '\n';
    }

    return 0;
}
