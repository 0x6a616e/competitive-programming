#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, m, c = 0;
        char square;

        while (cin >> n >> m && n && m) {
                c++;
                vector<vector<int>> tablero(n, vector<int> (m, 0));

                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                cin >> square;
                                if (square == '*') {
                                        tablero[i][j] = -1;
                                }
                        }
                }

                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (tablero[i][j] != -1) {
                                        if (i > 0 && j > 0 && tablero[i - 1][j - 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (i > 0 && tablero[i - 1][j] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (i > 0 && j < m - 1 && tablero[i - 1][j + 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (j < m - 1 && tablero[i][j + 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (i < n - 1 && j < m - 1 && tablero[i + 1][j + 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (i < n - 1 && tablero[i + 1][j] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (i < n - 1 && j > 0 && tablero[i + 1][j - 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                        if (j > 0 && tablero[i][j - 1] == -1) {
                                                tablero[i][j]++;
                                        }
                                }
                        }
                }

                if (c > 1) {
                        cout << '\n';
                }
                cout << "Field #" << c << ":\n";
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (tablero[i][j] == -1) {
                                        cout << '*';
                                } else {
                                        cout << tablero[i][j];
                                }
                        }
                        cout << '\n';
                }
        }
        
        return 0;
}
