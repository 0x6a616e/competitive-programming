// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<long long> memo(x + 1, 0);
    vector<int> coins(n);
    memo[0] = 1;
    for (int i = 0; i < n; ++i) cin >> coins[i];

    sort(coins.begin(), coins.end());

    for (int i = 1; i <= x; ++i) {
        long long curr_sol = 0;
        for (int coin : coins) {
            if (coin > i) break;
            curr_sol += memo[i - coin];
            curr_sol %= MOD;
        }
        memo[i] = curr_sol;
    }

    cout << memo[x] << endl;

    return 0;
}
