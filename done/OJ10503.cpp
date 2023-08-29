#include <bits/stdc++.h>

using namespace std;

bool solve(vector<pair<int, int>> &curr, int n, vector<pair<int, int>> &options,
           pair<int, int> &derecha, int usadas) {
    if ((int)curr.size() == n + 1) {
        if (curr.back().second == derecha.first)
            return true;
        else
            return false;
    } else {
        bool posible = false;
        for (int i = 0; i < (int)options.size(); ++i) {
            if (!(usadas & (1 << i))) {
                if (curr.back().second == options[i].first ||
                    curr.back().second == options[i].second) {
                    if (curr.back().second == options[i].second)
                        swap(options[i].first, options[i].second);
                    curr.push_back(options[i]);
                    posible = posible || solve(curr, n, options, derecha,
                                               usadas | (1 << i));
                    curr.pop_back();
                }
            }
        }
        return posible;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n && n) {
        int m;
        cin >> m;
        pair<int, int> izquierda, derecha;
        cin >> izquierda.first;
        cin >> izquierda.second;
        cin >> derecha.first;
        cin >> derecha.second;
        vector<pair<int, int>> dominoes(m);
        for (int i = 0; i < m; ++i) {
            cin >> dominoes[i].first;
            cin >> dominoes[i].second;
        }
        vector<pair<int, int>> curr;
        curr.reserve(m * 2);
        curr.push_back(izquierda);
        if (solve(curr, n, dominoes, derecha, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
