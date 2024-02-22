// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000000;
int memo[1000001];

int solve(int n) {
    if (memo[n] == -1) {
        int copy_n = n;
        int minimum = MAX;
        while (copy_n > 0) {
            int digit = copy_n % 10;
            if (digit != 0) minimum = min(minimum, 1 + solve(n - digit));
            copy_n /= 10;
        }
        memo[n] = minimum;
    }
    return memo[n];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) memo[i] = -1;
    for (int i = 1; i < 10; ++i) memo[i] = 1;
    cout << solve(n) << '\n';

    return 0;
}
