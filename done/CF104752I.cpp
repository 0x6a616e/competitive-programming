#include <bits/stdc++.h>

#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ull memo[1001];
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        memo[0] = 1;
        for (int i = 1; i <= n; ++i) {
            memo[i] = memo[i - 1];
            memo[i] += (1ULL * a * memo[i - 1]) % MOD;
            memo[i] += (1ULL * b * memo[i - 1]) % MOD;
            memo[i] %= MOD;
        }
        cout << memo[n] << '\n';
    }

    return 0;
}
