#include <bits/stdc++.h>

using namespace std;

vector<long long> memo;

long long solve(vector<long long> &x, int index) {
    if (index < 0) return 0;
    if (memo[index] == -1) {
        long long a = 0;
        if (index > 0) a = x[index - 1] + solve(x, index - 3);
        long long b = x[index] + solve(x, index - 2);
        memo[index] = max(a, b);
    }
    return memo[index];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    int c = 0;

    while (t--) {
        int n;
        cin >> n;

        memo.clear();
        memo.resize(n + 1, -1);

        vector<long long> x(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        if (n == 0) {
            cout << "Case " << ++c << ": 0\n";
        } else if (n == 1) {
            cout << "Case " << ++c << ": " << x[0] << "\n";
        } else {
            cout << "Case " << ++c << ": " << solve(x, n - 1) << "\n";
        }
    }

    return 0;
}
