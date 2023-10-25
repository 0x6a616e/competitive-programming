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

        int x[n];
        int y[n];

        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> y[i];

        vector<int> ordenado(n);

        for (int i = 0; i < n; ++i) ordenado[i] = x[i] - y[i];
        sort(ordenado.begin(), ordenado.end());

        int i = 0;
        int j = n - 1;
        int sol = 0;
        while (i < j) {
            if (ordenado[i] + ordenado[j] <= 0) {
                ++sol;
                ++i;
                --j;
            } else {
                --j;
            }
        }

        cout << sol << '\n';
    }

    return 0;
}
