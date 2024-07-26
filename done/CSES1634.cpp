// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> memo(x + 1, -1);
    vector<int> coins(n);
    memo[0] = 0;
    for (int i = 0; i < n; ++i) {
        int ci;
        cin >> ci;
        coins[i] = ci;
        if (ci < x) memo[ci] = 1;
    }

    sort(coins.begin(), coins.end());

    for (int i = 0; i <= x; ++i) {
        if (memo[i] != -1) continue;
        int curr_best = i + 1;
        for (int coin : coins) {
            if (coin > i) break;
            if (memo[i - coin] == -1) continue;
            curr_best = min(curr_best, memo[i - coin] + 1);
        }
        if (curr_best <= i) memo[i] = curr_best;
    }

    cout << memo[x] << endl;

    return 0;
}
