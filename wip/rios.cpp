#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph, memo;

int solve(int begin, int end) {
    if (memo[begin][end] != -1) {
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

    return 0;
}
