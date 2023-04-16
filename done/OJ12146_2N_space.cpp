#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100001;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int filas, columnas, caja;
        int memo_fila[MAX_SIZE], memo_totales[MAX_SIZE];

        while (cin >> filas >> columnas && (filas || columnas)) {
                for (int fila = 0; fila < filas; fila++) {
                        for (int columna = 0; columna < columnas; columna++) {
                                cin >> caja;
                                if (columna == 0) {
                                        memo_fila[0] = caja;
                                } else if (columna == 1) {
                                        memo_fila[1] = max(caja, memo_fila[0]);
                                } else {
                                        memo_fila[columna] = max(caja + memo_fila[columna - 2], memo_fila[columna - 1]);
                                }
                        }

                        if (fila == 0) {
                                memo_totales[0] = memo_fila[columnas - 1];
                        } else if (fila == 1) {
                                memo_totales[1] = max(memo_totales[0], memo_fila[columnas - 1]);
                        } else {
                                memo_totales[fila] = max(memo_fila[columnas - 1] + memo_totales[fila - 2], memo_totales[fila - 1]);
                        }
                }
                cout << memo_totales[filas - 1] << '\n';
        }

        return 0;
}
