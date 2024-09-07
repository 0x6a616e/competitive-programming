#include <bits/stdc++.h>

using namespace std;

void clean(int i, int j, vector<vector<char>> &grid) {
    if (grid[i][j] == '#') return;
    grid[i][j] = '#';
    if (i > 0) clean(i - 1, j, grid);
    if (i + 1 < (int)grid.size()) clean(i + 1, j, grid);
    if (j > 0) clean(i, j - 1, grid);
    if (j + 1 < (int)grid[i].size()) clean(i, j + 1, grid);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> grid[i][j];

    int sol = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                ++sol;
                clean(i, j, grid);
            }
        }

    cout << sol << endl;

    return 0;
}
