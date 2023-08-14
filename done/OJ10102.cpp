#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int m;
    while (cin >> m) {
        char n;
        vector<pair<int, int>> ones;
        vector<pair<int, int>> threes;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> n;
                if (n == '1') ones.push_back({j, i});
                if (n == '3') threes.push_back({j, i});
            }
        }

        int maximo = 0;
        for (pair<int, int> i : ones) {
            int minimo = m * 2;
            for (pair<int, int> j : threes) {
                int d = abs(i.first - j.first) + abs(i.second - j.second);
                minimo = min(minimo, d);
            }
            maximo = max(maximo, minimo);
        }

        cout << maximo << '\n';
    }

    return 0;
}
