// https://codeforces.com/contest/1786/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, w, h, wi, hi;
        cin >> n >> w >> h;

        vector<pair<int, int>> ws(n);
        for (int i = 0; i < n; ++i) {
            cin >> wi;
            ws[i].first = wi - w;
            ws[i].second = wi + w;
        }

        vector<pair<int, int>> hs(n);
        for (int i = 0; i < n; ++i) {
            cin >> hi;
            hs[i].first = hi - h;
            hs[i].second = hi + h;
        }

        pair<int, int> sol = {ws[0].first - hs[0].first,
                              ws[n - 1].second - hs[n - 1].second};
        for (int i = 0; i < n; ++i) {
            sol.first = max(sol.first, ws[i].first - hs[i].first);
            sol.second = min(sol.second, ws[i].second - hs[i].second);
        }

        if (sol.first <= sol.second)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
