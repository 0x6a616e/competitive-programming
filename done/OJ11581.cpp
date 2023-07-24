#include <bits/stdc++.h>

using namespace std;

void TransformGrid(vector<vector<int>> &source, vector<vector<int>> &target) {
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            target[i][j] = source[i - 1][j] + source[i][j + 1] +
                           source[i + 1][j] + source[i][j - 1];
            target[i][j] %= 2;
        }
    }
}

int GridToNumber(vector<vector<int>> &source) {
    bitset<9> n;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (source[1 + i][1 + j]) {
                n.set(8 - i * 3 - j);
            }
        }
    }
    return (int)n.to_ulong();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    string linea;

    cin >> t;
    getline(cin, linea);

    while (t--) {
        vector<vector<int>> past_grid(5, vector<int>(5, 0));
        vector<vector<int>> current_grid(5, vector<int>(5, 0));
        unordered_map<int, bool> visited;

        getline(cin, linea);

        for (int i = 0; i < 3; ++i) {
            getline(cin, linea);
            for (int j = 0; j < 3; ++j) {
                past_grid[i + 1][j + 1] = (linea[j] - '0');
            }
        }

        if (GridToNumber(past_grid) == 0) {
            cout << "-1\n";
        } else {
            int c = -1;
            while (GridToNumber(past_grid) != 0) {
                c++;
                TransformGrid(past_grid, current_grid);
                past_grid = current_grid;
            }
            cout << c << '\n';
        }
    }

    return 0;
}
