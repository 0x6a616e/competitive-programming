// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

unsigned long long solve(vector<unsigned long long> &memo, int n) {
    if (memo[n] == -1) {
        if (n == 0) {
            memo[n] = 1;
        } else {
            unsigned long long sol = 0;

            for (int i = 1; i <= min(6, n); ++i) sol += solve(memo, n - i);

            memo[n] = sol % MOD;
        }
    }
    return memo[n];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<unsigned long long> memo(n + 1, -1);
    cout << solve(memo, n) << endl;

    return 0;
}
