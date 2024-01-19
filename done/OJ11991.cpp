#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m) {
        unordered_map<int, vector<int>> ady_list;

        int num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            ady_list[num].push_back(i + 1);
        }

        int k, v;
        for (int i = 0; i < m; ++i) {
            cin >> k >> v;
            if (k > ady_list[v].size())
                cout << "0\n";
            else
                cout << ady_list[v][k - 1] << '\n';
        }
    }

    return 0;
}
