#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> memo(n, vector<int>(n));
    for (int i = 0; i + 1 < n; ++i) memo[i][i + 1] = abs(a[i] - a[i + 1]);
    for (int i = 2; i < n; ++i)
        for (int j = 0; j + i < n; ++j)
            memo[j][j + i] = min(min(memo[j][j + i - 1], memo[j + 1][j + i]), abs(a[j] - a[j + i]));

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << memo[l][r] << '\n';
    }

    return 0;
}
