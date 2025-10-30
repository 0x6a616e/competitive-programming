#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    array<int, 3> nums;
    for (int &i : nums) {
        cin >> i;
    }
    sort(nums.begin(), nums.end());

    int d1 = nums[1] - nums[0];
    int d2 = nums[2] - nums[1];
    int ans = 0;
    if (d1 == d2) {
        ans = nums[2] + d1;
    } else if (d1 < d2) {
        ans = nums[1] + d1;
    } else if (d2 < d1) {
        ans = nums[0] + d2;
    }
    cout << ans << '\n';

    return 0;
}
