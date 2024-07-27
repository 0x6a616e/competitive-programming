// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> sol(x + 1, 0);
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());

    for (int coin : coins) {
        if (coin > x) break;
        ++sol[coin];
        for (int i = 0; i <= x; ++i) {
            if (i + coin > x) break;
            if (sol[i] == 0) continue;
            sol[i + coin] += sol[i];
            sol[i + coin] %= MOD;
        }
    }

    cout << sol[x] << endl;

    return 0;
}
