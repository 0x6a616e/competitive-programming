#include <bits/stdc++.h>

using namespace std;

bool gana(char a, char b) {
        if (a == 'R' && b == 'S') {
                return true;
        }
        if (a == 'S' && b == 'P') {
                return true;
        }
        if (a == 'P' && b == 'R') {
                return true;
        }
        return false;
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        while (t--) {
                int r, c, n;
                cin >> r >> c >> n;

                vector<vector<char>> tablero(r, vector<char> (c)), tablero2;

                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                                cin >> tablero[i][j];
                        }
                }

                tablero2 = tablero;

                while (n--) {
                        for (int i = 0; i < r; i++) {
                                for (int j = 0; j < c; j++) {
                                        if (j > 0) {
                                                if (gana(tablero[i][j], tablero[i][j - 1])) {
                                                        tablero2[i][j - 1] = tablero[i][j];
                                                } else if (tablero[i][j] != tablero[i][j - 1]) {
                                                        tablero2[i][j] = tablero[i][j - 1];
                                                }
                                        }
                                        if (i > 0) {
                                                if (gana(tablero[i][j], tablero[i - 1][j])) {
                                                        tablero2[i - 1][j] = tablero[i][j];
                                                } else if (tablero[i][j] != tablero[i - 1][j]) {
                                                        tablero2[i][j] = tablero[i - 1][j];
                                                }
                                        }
                                }
                        }

                        tablero = tablero2;
                }

                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                                cout << tablero[i][j];
                        }
                        cout << '\n';
                }
                if (t > 0) {
                        cout << '\n';
                }
        }
        
        return 0;
}
