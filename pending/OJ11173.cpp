#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t, n, k;

        cin >> t;

        for (int _ = 0; _ < t; _++) {
                cin >> n >> k;
                int sol = 0;
                bool reves = false;
                for (int i = n; i > 0; i--) {
                        if (!reves && k >= (1 << (i - 1))) {
                                sol = sol | (1 << (i - 1));
                                reves = !reves;
                                k -= (1 << (i - 1));
                        } else if (reves && k < (1 << (i - 1))) {
                                sol = sol | (1 << (i - 1));
                                reves = !reves;
                        } else if (reves && k >= (1 << (i - 1))) {
                                k -= (1 << (i - 1));
                        }
                }
                cout << sol << '\n';
        }
        
        return 0;
}
