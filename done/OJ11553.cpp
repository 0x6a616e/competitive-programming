#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int grid[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> grid[i][j];
        int nums[n];
        for (int i = 0; i < n; ++i) nums[i] = i;
        int mejor = 1000;
        do {
            int total = 0;
            for (int i = 0; i < n; ++i) total += grid[i][nums[i]];
            mejor = min(mejor, total);
        } while (next_permutation(nums, nums + n));
        cout << mejor << endl;
    }
    return 0;
}
