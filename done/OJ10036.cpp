#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<int> nums;
vector<vector<int>> memo;

bool solve(int acum, int index) {
    if (acum < 0) acum += k;
    if (memo[acum][index] == -1) {
        if (index == n - 1) {
            memo[acum][index] = (acum == 0);
        } else {
            memo[acum][index] =
                solve((acum + nums[index + 1]) % k, index + 1) ||
                solve((acum - nums[index + 1]) % k, index + 1);
        }
    }
    return memo[acum][index];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        nums.clear();
        nums.resize(n);

        memo.clear();
        memo.resize(k + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            nums[i] %= k;
            if (nums[i] < 0) nums[i] += k;
        }

        if (solve(nums[0], 0))
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }

    return 0;
}
