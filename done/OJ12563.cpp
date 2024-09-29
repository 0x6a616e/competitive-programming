#include <bits/stdc++.h>

using namespace std;

vector<unordered_map<int, pair<int, int>>> memo;

pair<int, int> solve(vector<int> &songs, int limit, int songs_left, int acum) {
    pair<int, int> invalid = {-1, -1};
    if (acum >= limit) return invalid;
    if (songs_left == 0) return {0, acum};
    if (memo[songs_left].count(acum) == 0) {
        int i = (int)songs.size() - songs_left;
        pair<int, int> choose = solve(songs, limit, songs_left - 1, acum + songs[i]);
        pair<int, int> not_choose = solve(songs, limit, songs_left - 1, acum);
        if (choose != invalid) ++choose.first;
        if (choose == invalid)
            memo[songs_left][acum] = not_choose;
        else if (not_choose == invalid)
            memo[songs_left][acum] = choose;
        else if (choose >= not_choose)
            memo[songs_left][acum] = choose;
        else
            memo[songs_left][acum] = not_choose;
    }
    return memo[songs_left][acum];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int case_n = 1; case_n <= t; ++case_n) {
        int n, w;
        cin >> n >> w;
        memo.clear();
        memo.resize(n + 1);
        vector<int> songs(n);
        for (int i = 0; i < n; ++i) cin >> songs[i];
        sort(songs.begin(), songs.end());

        pair<int, int> sol = solve(songs, w, n, 0);
        ++sol.first;
        sol.second += 678;

        cout << "Case " << case_n << ": " << sol.first << ' ' << sol.second << '\n';
    }

    return 0;
}
