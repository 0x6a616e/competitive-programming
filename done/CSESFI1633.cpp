// https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int memo[n + 1];
    memo[0] = 0;

    for (int i = 1; i <= n; ++i) {
        memo[i] = (i <= 6 ? 1 : 0);
        for (int j = max(0, i - 6); j < i; ++j) memo[i] = (memo[i] + memo[j]) % MOD;
    }

    cout << memo[n] << '\n';

    return 0;
}
