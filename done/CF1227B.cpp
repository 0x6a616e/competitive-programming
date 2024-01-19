// https://codeforces.com/problemset/problem/1227/B

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

        set<int> used;
        int currMin = 1;
        int currMax = -1;
        vector<int> sol;
        sol.reserve(n);
        for (int i = 0; i < n; ++i) {
            int q;
            cin >> q;
            if (q > currMax) {
                currMax = q;
                used.insert(q);
                sol.push_back(q);
            } else {
                while (used.count(currMin) && currMin < currMax) {
                    ++currMin;
                }
                if (!used.count(currMin)) {
                    used.insert(currMin);
                    sol.push_back(currMin);
                }
            }
        }

        if (sol.size() != n) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; ++i) {
                cout << (i ? " " : "") << sol[i];
            }
            cout << "\n";
        }
    }

    return 0;
}
