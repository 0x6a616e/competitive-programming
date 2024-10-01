#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int limit = 100000;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> dp;
    unordered_map<int, int> d;
    int best = 1;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        dp[nums[i]] = d[nums[i]] = 1;

        if (is_prime[nums[i]]) continue;

        int local_best = 0;
        for (int j = 2; j * j <= nums[i]; ++j) {
            if (nums[i] % j == 0) {
                int a = j;
                int b = nums[i] / j;
                local_best = max(local_best, d[a]);
                local_best = max(local_best, d[b]);
            }
        }
        dp[nums[i]] = local_best + 1;
        d[nums[i]] = dp[nums[i]];
        best = max(best, dp[nums[i]]);
        for (int j = 2; j * j <= nums[i]; ++j) {
            if (nums[i] % j == 0) {
                int a = j;
                int b = nums[i] / j;
                d[a] = d[b] = dp[nums[i]];
            }
        }
    }

    cout << best << endl;

    return 0;
}
