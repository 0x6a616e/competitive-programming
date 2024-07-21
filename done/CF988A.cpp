#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<int> uniques;
    vector<int> sol;
    sol.reserve(n);

    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (!uniques.count(ai)) {
            uniques.insert(ai);
            sol.push_back(i + 1);
        }
    }

    if (uniques.size() < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < k; ++i) cout << (i ? " " : "") << sol[i];
    }

    return 0;
}
