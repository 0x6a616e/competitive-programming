// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<int> t;
    map<int, int> tickets;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (!tickets[c]) {
            t.insert(c);
        }
        ++tickets[c];
    }
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        auto it = t.upper_bound(c);
        if (it != t.begin()) {
            --it;
        }
        if (t.size() > 0 && *it <= c) {
            --tickets[*it];
            cout << *it << '\n';
            if (tickets[*it] == 0) t.erase(it);
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
