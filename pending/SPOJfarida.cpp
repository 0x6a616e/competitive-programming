#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long> &memo, vector<long long> &fila, int columna) {
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

    int casos, monstruos;

    cin >> casos;

    for (int i = 0; i < casos; i++) {
        cin >> monstruos;
        if (monstruos == 0) {
            cout << "Case " << i + 1 << ": 0\n";
        } else {
            vector<long long> camino(monstruos), memo(monstruos, -1);
            for (int j = 0; j < monstruos; j++) {
                cin >> camino[j];
            }
            cout << "Case " << i + 1 << ": " << solve(memo, camino, 0) << '\n';
        }
    }

    return 0;
}
