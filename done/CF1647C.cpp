// https://codeforces.com/problemset/problem/1647/C

#include <bits/stdc++.h>

using namespace std;

string paintable(vector<vector<char>> &grid, int y, int x) {
    if (y > 0 && grid[y - 1][x] == '0') return "up";
    if (x > 0 && grid[y][x - 1] == '0') return "left";
    return "no";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid_source(n, vector<char>(m));
        vector<vector<char>> grid_goal(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> grid_goal[i][j];
                grid_source[i][j] = '0';
            }

        vector<pair<int, int>> sol;
        bool impossible = false;
        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j) {
                if (grid_goal[i][j] == '1') {
                    string dir = paintable(grid_source, i, j);
                    if (dir == "up") {
                        grid_source[i][j] = '1';
                        sol.push_back({i, j + 1});
                        sol.push_back({i + 1, j + 1});
                    } else if (dir == "left") {
                        grid_source[i][j] = '1';
                        sol.push_back({i + 1, j});
                        sol.push_back({i + 1, j + 1});
                    } else
                        impossible = true;
                }
            }
        if (impossible)
            cout << "-1\n";
        else {
            cout << sol.size() / 2 << '\n';
            for (int i = 0; i < (int)sol.size(); i += 2) {
                cout << sol[i].first << ' ' << sol[i].second << ' '
                     << sol[i + 1].first << ' ' << sol[i + 1].second << '\n';
            }
        }
    }

    return 0;
}
