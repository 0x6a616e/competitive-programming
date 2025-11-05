#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int solve(vector<vector<char>> &grid, int i, int j) {
    if (memo[i][j] == -1) {
        int ans = 0;
        char next = grid[i][j] + 1;
        if (i > 0 && j > 0 && grid[i - 1][j - 1] == next) {
            ans = max(ans, solve(grid, i - 1, j - 1));
        }
        if (i > 0 && grid[i - 1][j] == next) {
            ans = max(ans, solve(grid, i - 1, j));
        }
        if (i > 0 && j + 1 < (int)grid[0].size() && grid[i - 1][j + 1] == next) {
            ans = max(ans, solve(grid, i - 1, j + 1));
        }
        if (j + 1 < (int)grid[0].size() && grid[i][j + 1] == next) {
            ans = max(ans, solve(grid, i, j + 1));
        }
        if (i + 1 < (int)grid.size() && j + 1 < (int)grid[0].size() && grid[i + 1][j + 1] == next) {
            ans = max(ans, solve(grid, i + 1, j + 1));
        }
        if (i + 1 < (int)grid.size() && grid[i + 1][j] == next) {
            ans = max(ans, solve(grid, i + 1, j));
        }
        if (i + 1 < (int)grid.size() && j > 0 && grid[i + 1][j - 1] == next) {
            ans = max(ans, solve(grid, i + 1, j - 1));
        }
        if (j > 0 && grid[i][j - 1] == next) {
            ans = max(ans, solve(grid, i, j - 1));
        }
        memo[i][j] = ans + 1;
    }
    return memo[i][j];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    memo.resize(n, vector<int>(m, -1));
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, solve(grid, i, j));
        }
    }
    cout << ans << endl;

    return 0;
}
