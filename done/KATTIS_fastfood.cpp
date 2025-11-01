#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> pertains(m + 1, -1);
        vector<int> values(n);
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            while (k--) {
                int req;
                cin >> req;
                pertains[req] = i;
            }
            cin >> values[i];
        }
        for (int i = 1; i <= m; ++i) {
            int ti;
            cin >> ti;
            if (pertains[i] != -1) {
                if (ans[pertains[i]] == -1 || ti < ans[pertains[i]]) {
                    ans[pertains[i]] = ti;
                }
            }
        }
        int ans_f = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != -1) {
                ans_f += ans[i] * values[i];
            }
        }
        cout << ans_f << '\n';
    }

    return 0;
}
