#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<char>> path(r, vector<char>(c, '?'));
    pair<int, int> exit;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') exit = {i, j};
            if (grid[i][j] == 'X' || grid[i][j] == '#') path[i][j] = '*';
        }
    }
    path[exit.first][exit.second] = 'E';
    queue<pair<int, int>> pending;
    pending.push(exit);
    set<char> directions = {'L', 'R', 'U', 'D', 'E'};
    while (!pending.empty()) {
        pair<int, int> curr = pending.front();
        int i = curr.first;
        int j = curr.second;
        pending.pop();
        if (path[i][j] != '?' && path[i][j] != 'E') continue;
        if (j > 0 && directions.count(path[i][j - 1])) path[i][j] = 'L';
        else if (i + 1 < r && directions.count(path[i + 1][j])) path[i][j] = 'D';
        else if (j + 1 < c && directions.count(path[i][j + 1])) path[i][j] = 'R';
        else if (i > 0 && directions.count(path[i - 1][j])) path[i][j] = 'U';

        if (j > 0) pending.push({i, j - 1});
        if (j + 1 < c) pending.push({i, j + 1});
        if (i > 0) pending.push({i - 1, j});
        if (i + 1 < r) pending.push({i + 1, j});
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        --i;--j;
        if (grid[i][j] == '#') cout << "W";
        else if (grid[i][j] == 'X') cout << "X";
        else if (grid[i][j] == 'E') cout << "E";
        else cout << path[i][j];
        cout << '\n';
    }

    return 0;
}
