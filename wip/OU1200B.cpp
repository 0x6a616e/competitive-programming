#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int p, t, n, m, k;
    vector<int> cols;

    cin >> t;

    while (t--) {
        cin >> n >> m >> k;
        cols.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> cols[i];
        }

        for (p = 0; p < n - 1; p++) {
            if (cols[p] + k > cols[p + 1]) {
                m += (cols[p] - (cols[p + 1] - k));
            } else if (cols[p] + k < cols[p + 1]) {
                if (m >= (cols[p + 1] - k - cols[p])) {
                    m -= (cols[p + 1] - k - cols[p]);
                } else {
                    
                    break;
                }
            }
        }

        if (p == n - 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
