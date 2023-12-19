#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> hp(n);
        for (int i = 0; i < n; ++i) cin >> hp[i].second;
        for (int i = 0; i < n; ++i) cin >> hp[i].first;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            m(hp.begin(), hp.end());

        int dmg = 0;
        while (k > 0 && !m.empty()) {
            dmg += k;
            while (!m.empty() && m.top().second <= dmg) {
                m.pop();
            }

            if (!m.empty()) {
                k -= m.top().first;
            }
        }

        if (m.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
