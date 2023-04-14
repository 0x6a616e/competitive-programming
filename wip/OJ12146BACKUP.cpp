#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &memo, vector<int> &fila, int num_fila, int columna) {
    if (memo[num_fila][columna] == -1) {
        if (fila.size() - columna == 3) {
            memo[num_fila][columna] = max(fila[columna] + solve(memo, fila, num_fila, columna + 2), fila[columna + 1]);
        } else if (fila.size() - columna == 2) {
            memo[num_fila][columna] = max(fila[columna], fila[columna + 1]);
        } else if (fila.size() - columna == 1) {
            memo[num_fila][columna] = fila[columna];
        } else {
            memo[num_fila][columna] = max(fila[columna] + solve(memo, fila, num_fila, columna + 2), fila[columna + 1] + solve(memo, fila, num_fila, columna + 3));
        }
    }
    return memo[num_fila][columna];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int filas, columnas;

    while (cin >> filas >> columnas && !(filas == 0 && columnas == 0)) {
        vector<vector<int>> memo(max(filas + 1, columnas + 1), vector<int>(max(filas, columnas), -1));
        vector<vector<int>> matriz(filas, vector<int>(columnas, 0));
        vector<int> maximos(filas);

        for (int fila = 0; fila < filas; fila++) {
            for (int columna = 0; columna < columnas; columna++) {
                cin >> matriz[fila][columna];
            }
            maximos[fila] = solve(memo, matriz[fila], fila, 0);
        }
        cout << solve(memo, maximos, filas, 0) << '\n';
    }
    
    return 0;
}
