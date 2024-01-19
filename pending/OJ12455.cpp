#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L;
        cin >> L;
        unordered_map<int, int> bars;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> bars[1 << i];
        bool found = false;
        for (int i = 0; i < (1 << n) && !found; ++i) {
            int l = 0;
            for (pair<int, int> bar : bars) {
                if (bar.first & i) l += bar.second;
                if (l > L) break;
            }
            if (l == L) found = true;
        }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
