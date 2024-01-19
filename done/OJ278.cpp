#include <bits/stdc++.h>

using namespace std;

bool valido(vector<int> &tablero, int row) {
        for (int i = 0; i < tablero.size(); i++) {
                if (tablero[i] == row) {
                        return false;
                }
                if (abs(i - (int) tablero.size()) == abs(tablero[i] - row)) {
                        return false;
                }
        }
        return true;
}

void solve(vector<int> &tablero, int &solucion, int rows, int columns) {
        solucion = max(solucion, (int) tablero.size());
        for (int i = 0; i < rows; i++) {
                if (valido(tablero, i)) {
                        tablero.push_back(i);
                        solve(tablero, solucion, rows, columns);
                        tablero.pop_back();
                }
        }
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        while (t--) {
                char pieza;
                int r, c;
                
                cin >> pieza >> r >> c;

                if (pieza == 'r') {
                        cout << min(r, c) << '\n';
                } else if (pieza == 'k') {
                        cout << ceil((r * c) / 2.0) << '\n';
                } else if (pieza == 'Q') {
                        int sol = 0;
                        vector<int> pos;

                        solve(pos, sol, r, c);
                        
                        cout << sol << '\n';
                } else if (pieza == 'K') {
                        cout << ceil(c / 2.0) * ceil(r / 2.0) << '\n';
                }
        }
        
        return 0;
}
