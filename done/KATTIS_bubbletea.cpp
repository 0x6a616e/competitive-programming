#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> tea(n);
    for (int &ti : tea) {
        cin >> ti;
    }

    int m;
    cin >> m;
    vector<int> top(m);
    for (int &ti : top) {
        cin >> ti;
    }

    int best = -1;
    for (int i = 0; i < n; ++i) {
        int curr = tea[i];
        int k;
        cin >> k;
        while (k--) {
            int ti;
            cin >> ti;
            if (best == -1 || curr + top[ti - 1] < best) {
                best = curr + top[ti - 1];
            }
        }
    }

    int x;
    cin >> x;
    int ans = x / best;
    if (x >= best) {
        --ans;
    }

    cout << ans << '\n';

    return 0;
}
