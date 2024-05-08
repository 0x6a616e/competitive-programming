#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int solve(vector<vector<char>> &maze, vector<vector<int>> &memo, int x, int y) {
    if (x >= maze.size() || y >= maze.size()) return 0;
    if (maze[y][x] == '*') return 0;
    if (x == maze.size() - 1 && y == maze.size() - 1) return 1;
    if (memo[y][x] == -1) {
        memo[y][x] = (solve(maze, memo, x + 1, y) + solve(maze, memo, x, y + 1)) % MOD;
    }
    return memo[y][x];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<char>> maze(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> memo(n, vector<int>(n, -1));
    cout << solve(maze, memo, 0, 0) << '\n';

    return 0;
}
