#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &memo, vector<int> &fila, int columna) {
    if (memo[columna] == -1) {
        if (fila.size() - columna == 3) {
            memo[columna] = max(fila[columna] + solve(memo, fila, columna + 2), fila[columna + 1]);
        } else if (fila.size() - columna == 2) {
            memo[columna] = max(fila[columna], fila[columna + 1]);
        } else if (fila.size() - columna == 1) {
            memo[columna] = fila[columna];
        } else {
            memo[columna] = max(fila[columna] + solve(memo, fila, columna + 2), fila[columna + 1] + solve(memo, fila, columna + 3));
        }
    }
    return memo[columna];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int filas, columnas;

    while (cin >> filas >> columnas && !(filas == 0 && columnas == 0)) {
        vector<int> lectura_fila(columnas), maximos(filas), memo(columnas);
        for (int fila = 0; fila < filas; fila++) {
            fill(memo.begin(), memo.end(), -1);
            for (int columna = 0; columna < columnas; columna++) {
                cin >> lectura_fila[columna];
            }
            maximos[fila] = solve(memo, lectura_fila, 0);
        }
        memo.resize(filas);
        fill(memo.begin(), memo.end(), -1);
        cout << solve(memo, maximos, 0) << '\n';
    }
    
    return 0;
}
