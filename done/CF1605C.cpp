#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int bs, cs;
        bs = cs = 0;
        int last_a = -1;
        int sol = n + 1;

        vector<pair<int, int>> diffs;
        diffs.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                if (last_a != -1) diffs.push_back({bs, cs});

                last_a = i;
                bs = cs = 0;
            }
            if (s[i] == 'b') ++bs;
            if (s[i] == 'c') ++cs;
        }

        for (pair<int, int> diff : diffs) {
            if (diff.first < 2 && diff.second < 2) {
                sol = min(sol, diff.first + diff.second + 2);
            }
        }

        if (sol > n) {
            for (int i = 0; i < (int)diffs.size() - 1; ++i) {
                pair<int, int> diff = {diffs[i].first + diffs[i + 1].first,
                                       diffs[i].second + diffs[i + 1].second};
                if (diff.first < 3 && diff.second < 3) {
                    sol = min(sol, diff.first + diff.second + 3);
                }
            }
        }

        if (sol > n)
            cout << "-1\n";
        else
            cout << sol << '\n';
    }

    return 0;
}
