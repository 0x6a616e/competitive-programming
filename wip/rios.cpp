#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph, memo;

int solve(int begin, int end) {
    if (memo[begin][end] == -1) {
        int min_dist = graph[begin][end];
        for (int i = begin + 1; i < end; ++i) {
            min_dist = min(min_dist, solve(begin, i) + solve(i, end));
        }
        memo[begin][end] = min_dist;
    }
    return memo[begin][end];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;
        graph.resize(n, vector<int>(n));
        memo.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cin >> graph[i][j];
                memo[i][j] = (i == j ? 0 : -1);
            }
        }
        solve(0, n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cout << (i == j ? "" : " ") << memo[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
