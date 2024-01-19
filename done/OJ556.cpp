#include <bits/stdc++.h>

using namespace std;

bool posible(vector<vector<int>> &maze, int x, int y, int dir) {
        if (dir == 0) {
                return maze[x - 1][y] != -1;
        } else if (dir == 1) {
                return maze[x][y + 1] != -1;
        } else if (dir == 2) {
                return maze[x + 1][y] != -1;
        } else if (dir == 3) {
                return maze[x][y - 1] != -1;
        }
}

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int r, c, x, y, dir;
        char tile;
        // vector<char> dirs = { 'u', 'r', 'd', 'l' };

        while (cin >> r >> c && r && c) {
                dir = 2;
                vector<int> res(5);
                vector<vector<int>> maze(r + 2, vector<int> (c + 2, -1));
                for (int row = 0; row < r; row++) {
                        for (int col = 0; col < c; col++) {
                                cin >> tile;
                                if (tile == '0') {
                                        maze[row + 1][col + 1] = 0;
                                }
                        }
                }

                x = r;
                y = 1;

                while (maze[r][1] < 2) {
                        if (posible(maze, x, y, dir)) {
                                maze[x][y]++;
                                if (dir == 0) {
                                        x--;
                                } else if (dir == 1) {
                                        y++;
                                } else if (dir == 2) {
                                        x++;
                                } else if (dir == 3) {
                                        y--;
                                }
                                maze[x][y]++;
                                dir = (dir + 1) % 4;
                        } else {
                                dir = (dir == 0 ? 3 : dir - 1);
                        }
                }
                
                for (int i = 0; i < (r + 2); i++) {
                        for (int j = 0; j < (c + 2); j++) {
                                if (maze[i][j] >= 0) {
                                        res[maze[i][j] / 2]++;
                                }
                        }
                }

                for (int i = 0; i < 5; i++) {
                        cout << setw(3) << res[i];
                }
                cout << '\n';
                
        }
        
        return 0;
}

