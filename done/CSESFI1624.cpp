#include <bits/stdc++.h>

using namespace std;

enum Square { f, r };

Square grid[8][8];

bool isDiagonal(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int solve(vector<int> &sol) {
    if (sol.size() == 8) return 1;

    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (grid[i][sol.size()] == Square::r) {
            continue;
        }

        if (find(sol.begin(), sol.end(), i) != sol.end()) {
            continue;
        }
        bool posible = true;
        for (int j = 0; j < (int)sol.size() && posible; ++j) {
            if (isDiagonal(j, sol[j], (int)sol.size(), i)) {
                posible = false;
                continue;
            }
        }

        if (posible) {
            sol.push_back(i);
            count += solve(sol);
            sol.pop_back();
        }
    }

    return count;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            if (s[j] == '.') {
                grid[i][j] = Square::f;
            } else if (s[j] == '*') {
                grid[i][j] = Square::r;
            }
        }
    }

    vector<int> sol;

    cout << solve(sol) << endl;

    return 0;
}
