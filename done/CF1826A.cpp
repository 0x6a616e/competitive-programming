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

        vector<int> acum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int l;
            cin >> l;
            for (int j = l; j <= n; ++j) ++acum[j];
        }

        int sol = -1;
        for (int i = n; i >= 0 && sol == -1; --i) {
            if (i + acum[i] == n) sol = i;
        }

        cout << sol << '\n';
    }

    return 0;
}
