#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 3;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int filas, columnas, caja;
        int memo_fila[MAX_SIZE];
        int memo_totales[MAX_SIZE];

        while (cin >> filas >> columnas && (filas || columnas)) {
                memset(memo_totales, 0, sizeof(memo_totales));
                for (int fila = 0; fila < filas; ++fila) {
                        memset(memo_fila, 0, sizeof(memo_fila));

                        for (int columna = 0; columna < columnas; ++columna) {
                                cin >> caja;
                                memo_fila[2] = max(caja + memo_fila[0], memo_fila[1]);
                                memo_fila[0] = memo_fila[1];
                                memo_fila[1] = memo_fila[2];
                        }

                        memo_totales[2] = max(memo_fila[2] + memo_totales[0], memo_totales[1]);
                        memo_totales[0] = memo_totales[1];
                        memo_totales[1] = memo_totales[2];
                }
                cout << memo_totales[2] << '\n';
        }

        return 0;
}
