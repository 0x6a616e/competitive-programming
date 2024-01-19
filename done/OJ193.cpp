#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &colores, int indice, vector<vector<int>> &adyacencias,
           pair<int, vector<int>> &mejor) {
    if (indice == (int)colores.size()) {
        int acum = 0;
        for (int &i : colores)
            if (i == -1) ++acum;
        if (acum > mejor.first) mejor = {acum, colores};
    } else {
        bool black_posible = true;
        for (int &i : adyacencias[indice + 1])
            if (colores[i - 1] == -1) black_posible = false;
        if (black_posible) {
            colores[indice] = -1;
            solve(colores, indice + 1, adyacencias, mejor);
            colores[indice] = 0;
        }
        colores[indice] = 1;
        solve(colores, indice + 1, adyacencias, mejor);
        colores[indice] = 0;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> colores(n, 0);
        vector<vector<int>> adyacencias(n + 1);
        pair<int, vector<int>> mejor = {0, {}};
        for (int i = 0; i < m; ++i) {
            int izquierda, derecha;
            cin >> izquierda >> derecha;
            if (izquierda < derecha)
                adyacencias[derecha].push_back(izquierda);
            else
                adyacencias[izquierda].push_back(derecha);
        }
        solve(colores, 0, adyacencias, mejor);
        cout << mejor.first << '\n';
        bool printed = false;
        for (int i = 0; i < (int)mejor.second.size(); ++i) {
            if (mejor.second[i] == -1) {
                if (printed) cout << ' ';
                printed = true;
                cout << i + 1;
            }
        }
        cout << '\n';
    }

    return 0;
}
