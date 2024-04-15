// https://cses.fi/problemset/task/1625

#include <bits/stdc++.h>

using namespace std;

string s, path;
int sol = 0;
bool grid[7][7];

void solve(int index, int x, int y) {
    if (x == 0 && y == 6) {
        if (index == 48) ++sol;
        return;
    }
    if ((x == 0 || x == 6) && y > 0 && !grid[y - 1][x] && y < 6 && !grid[y + 1][x]) return;
    if (index > 0 && path[index - 1] == 'L' && x > 0 && grid[y][x - 1] && y > 0 &&
        !grid[y - 1][x] && y < 6 && !grid[y + 1][x])
        return;
    if (index > 0 && path[index - 1] == 'R' && x < 6 && grid[y][x + 1] && y > 0 &&
        !grid[y - 1][x] && y < 6 && !grid[y + 1][x])
        return;
    if ((y == 0 || y == 6) && x > 0 && !grid[y][x - 1] && x < 6 && !grid[y][x + 1]) return;
    if (index > 0 && path[index - 1] == 'U' && y > 0 && grid[y - 1][x] && x > 0 &&
        !grid[y][x - 1] && x < 6 && !grid[y][x + 1])
        return;
    if (index > 0 && path[index - 1] == 'D' && y < 6 && grid[y + 1][x] && x > 0 &&
        !grid[y][x - 1] && x < 6 && !grid[y][x + 1])
        return;
    if ((s[index] == '?' || s[index] == 'U') && y > 0 && !grid[y - 1][x]) {
        grid[y - 1][x] = true;
        path[index] = 'U';
        solve(index + 1, x, y - 1);
        grid[y - 1][x] = false;
    }
    if ((s[index] == '?' || s[index] == 'R') && x < 6 && !grid[y][x + 1]) {
        grid[y][x + 1] = true;
        path[index] = 'R';
        solve(index + 1, x + 1, y);
        grid[y][x + 1] = false;
    }
    if ((s[index] == '?' || s[index] == 'D') && y < 6 && !grid[y + 1][x]) {
        grid[y + 1][x] = true;
        path[index] = 'D';
        solve(index + 1, x, y + 1);
        grid[y + 1][x] = false;
    }
    if ((s[index] == '?' || s[index] == 'L') && x > 0 && !grid[y][x - 1]) {
        grid[y][x - 1] = true;
        path[index] = 'L';
        solve(index + 1, x - 1, y);
        grid[y][x - 1] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j) grid[i][j] = false;
    grid[0][0] = true;

    cin >> s;
    path = s;

    solve(0, 0, 0);
    cout << sol << '\n';

    return 0;
}
