#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int m, n;

    while (cin >> m >> n) {
        vector<vector<pair<int, int>>> ady_list(m + 1);
        int r;
        for (int i = 1; i <= m; ++i) {
            cin >> r;
            ady_list[i].assign(r, {});
            for (int j = 0; j < r; ++j) {
                cin >> ady_list[i][j].first;
            }
            for (int j = 0; j < r; ++j) {
                cin >> ady_list[i][j].second;
            }
        }

        vector<vector<pair<int, int>>> rotated_list(n + 1);

        for (int i = 1; i <= m; ++i) {
            for (pair<int, int> p : ady_list[i]) {
                rotated_list[p.first].push_back({i, p.second});
            }
        }

        cout << n << ' ' << m << '\n';

        for (int i = 1; i <= n; ++i) {
            cout << rotated_list[i].size();
            for (pair<int, int> p : rotated_list[i]) {
                cout << ' ' << p.first;
            }
            cout << '\n';
            for (size_t j = 0; j < rotated_list[i].size(); ++j) {
                if (j > 0) cout << ' ';
                cout << rotated_list[i][j].second;
            }
            cout << '\n';
        }
    }

    return 0;
}
