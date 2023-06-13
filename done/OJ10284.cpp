#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string FEN, FEN_original;

        while (cin >> FEN) {
                FEN_original = FEN;
                vector<vector<int>> tablero(8, vector<int> (8, 0));
                int row = 0;
                int col = 0;

                for (size_t i = 0; i < FEN.size(); i++) {
                        FEN[i] = tolower(FEN[i]);
                        if (FEN[i] == '/') {
                                row++;
                                col = 0;
                        } else if (FEN[i] == 'p') {
                                tablero[row][col] = 1;
                                col++;
                        } else if (FEN[i] == 'n') {
                                tablero[row][col] = 1;
                                col++;
                        } else if (FEN[i] == 'b') {
                                tablero[row][col] = 1;
                                col++;
                        } else if (FEN[i] == 'r') {
                                tablero[row][col] = 1;
                                col++;
                        } else if (FEN[i] == 'q') {
                                tablero[row][col] = 1;
                                col++;
                        } else if (FEN[i] == 'k') {
                                tablero[row][col] = 1;
                                col++;
                        } else {
                                col += (FEN[i] - '0');
                        }
                }

                row = 0;
                col = 0;

                for (size_t i = 0; i < FEN.size(); i++) {
                        if (FEN[i] == '/') {
                                row++;
                                col = 0;
                        } else if (FEN[i] == 'p') {
                                if (FEN_original[i] == 'P') {
                                        if (row > 0) {
                                                if (col > 0) {
                                                        if (tablero[row - 1][col - 1] != 1) {
                                                                tablero[row - 1][col - 1] = 2;
                                                        }
                                                }
                                                if (col < 7) {
                                                        if (tablero[row - 1][col + 1] != 1) {
                                                                tablero[row - 1][col + 1] = 2;
                                                        }
                                                }
                                        }
                                } else {
                                        if (row < 7) {
                                                if (col > 0) {
                                                        if (tablero[row + 1][col - 1] != 1) {
                                                                tablero[row + 1][col - 1] = 2;
                                                        }
                                                }
                                                if (col < 7) {
                                                        if (tablero[row + 1][col + 1] != 1) {
                                                                tablero[row + 1][col + 1] = 2;
                                                        }
                                                }
                                        }
                                }
                                col++;
                        } else if (FEN[i] == 'n') {
                                if (row > 1 && col > 0) {
                                        if (tablero[row - 2][col - 1] != 1) {
                                                tablero[row - 2][col - 1] = 2;
                                        }
                                }
                                if (row > 1 && col < 7) {
                                        if (tablero[row - 2][col + 1] != 1) {
                                                tablero[row - 2][col + 1] = 2;
                                        }
                                }
                                if (row > 0 && col < 6) {
                                        if (tablero[row - 1][col + 2] != 1) {
                                                tablero[row - 1][col + 2] = 2;
                                        }
                                }
                                if (row < 7 && col < 6) {
                                        if (tablero[row + 1][col + 2] != 1) {
                                                tablero[row + 1][col + 2] = 2;
                                        }
                                }
                                if (row < 6 && col < 7) {
                                        if (tablero[row + 2][col + 1] != 1) {
                                                tablero[row + 2][col + 1] = 2;
                                        }
                                }
                                if (row < 6 && col > 0) {
                                        if (tablero[row + 2][col - 1] != 1) {
                                                tablero[row + 2][col - 1] = 2;
                                        }
                                }
                                if (row < 7 && col > 1) {
                                        if (tablero[row + 1][col - 2] != 1) {
                                                tablero[row + 1][col - 2] = 2;
                                        }
                                }
                                if (row > 0 && col > 1) {
                                        if (tablero[row - 1][col - 2] != 1) {
                                                tablero[row - 1][col - 2] = 2;
                                        }
                                }
                                col++;
                        } else if (FEN[i] == 'b') {
                                int r;
                                int c;

                                r = row - 1;
                                c = col - 1;
                                while (r >= 0 && c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                        c--;
                                }

                                r = row - 1;
                                c = col + 1;
                                while (r >= 0 && c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                        c++;
                                }

                                r = row + 1;
                                c = col - 1;
                                while (r <= 7 && c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                        c--;
                                }

                                r = row + 1;
                                c = col + 1;
                                while (r <= 7 && c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                        c++;
                                }

                                col++;
                        } else if (FEN[i] == 'r') {
                                int r;
                                int c;

                                r = row - 1;
                                c = col;
                                while (r >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                }

                                r = row;
                                c = col + 1;
                                while (c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        c++;
                                }

                                r = row + 1;
                                c = col;
                                while (r <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                }

                                r = row;
                                c = col - 1;
                                while (c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        c--;
                                }

                                col++;
                        } else if (FEN[i] == 'q') {
                                int r;
                                int c;

                                r = row - 1;
                                c = col - 1;
                                while (r >= 0 && c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                        c--;
                                }

                                r = row - 1;
                                c = col + 1;
                                while (r >= 0 && c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                        c++;
                                }

                                r = row + 1;
                                c = col - 1;
                                while (r <= 7 && c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                        c--;
                                }

                                r = row + 1;
                                c = col + 1;
                                while (r <= 7 && c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                        c++;
                                }

                                r = row - 1;
                                c = col;
                                while (r >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r--;
                                }

                                r = row;
                                c = col + 1;
                                while (c <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        c++;
                                }

                                r = row + 1;
                                c = col;
                                while (r <= 7 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        r++;
                                }

                                r = row;
                                c = col - 1;
                                while (c >= 0 && tablero[r][c] != 1) {
                                        tablero[r][c] = 2;
                                        c--;
                                }
                                
                                col++;
                        } else if (FEN[i] == 'k') {
                                if (row > 0) {
                                        if (tablero[row - 1][col] != 1) {
                                                tablero[row - 1][col] = 2;
                                        }
                                }
                                if (col < 7) {
                                        if (tablero[row][col + 1] != 1) {
                                                tablero[row][col + 1] = 2;
                                        }
                                }
                                if (row < 7) {
                                        if (tablero[row + 1][col] != 1) {
                                                tablero[row + 1][col] = 2;
                                        }
                                }
                                if (col > 0) {
                                        if (tablero[row][col - 1] != 1) {
                                                tablero[row][col - 1] = 2;
                                        }
                                }

                                if (row > 0) {
                                        if (col > 0) {
                                                if (tablero[row - 1][col - 1] != 1) {
                                                        tablero[row - 1][col - 1] = 2;
                                                }
                                        }
                                        if (col < 7) {
                                                if (tablero[row - 1][col + 1] != 1) {
                                                        tablero[row - 1][col + 1] = 2;
                                                }
                                        }
                                }
                                if (row < 7) {
                                        if (col > 0) {
                                                if (tablero[row + 1][col - 1] != 1) {
                                                        tablero[row + 1][col - 1] = 2;
                                                }
                                        }
                                        if (col < 7) {
                                                if (tablero[row + 1][col + 1] != 1) {
                                                        tablero[row + 1][col + 1] = 2;
                                                }
                                        }
                                }
                                col++;
                        } else {
                                col += (FEN[i] - '0');
                        }
                }
                int seguros = 0;

                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                                if (!tablero[i][j]) {
                                        seguros++;
                                }
                        }
                }

                cout << seguros << '\n';
        }
        
        return 0;
}
