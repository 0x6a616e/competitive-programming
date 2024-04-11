// https://onlinejudge.org/external/120/12022.pdf

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 11;

long long factorial[MAX_N + 1];
long long memo_s[MAX_N + 1];

long long comb(int n, int r) { return factorial[n] / (factorial[r] * factorial[n - r]); }

void solve(int n) {
    memo_s[n] = 0;
    for (int i = 1; i <= n; ++i) {
        memo_s[n] += comb(n, i) * memo_s[n - i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    factorial[0] = 1;
    for (int i = 1; i < MAX_N + 1; ++i) factorial[i] = factorial[i - 1] * i;

    memo_s[0] = 1;
    for (int i = 1; i < MAX_N + 1; ++i) solve(i);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << memo_s[n] << '\n';
    }

    return 0;
}
