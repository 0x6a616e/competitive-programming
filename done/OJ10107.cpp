#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    vector<int> nums;

    while (cin >> n) {
        nums.push_back(n);
        if (nums.size() % 2 == 0) {
            nth_element(nums.begin(), nums.begin() + nums.size() / 2,
                        nums.end());
            nth_element(nums.begin(), nums.begin() + nums.size() / 2 - 1,
                        nums.end());
            cout << (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2
                 << '\n';
        } else {
            nth_element(nums.begin(), nums.begin() + nums.size() / 2,
                        nums.end());
            cout << nums[nums.size() / 2] << '\n';
        }
    }

    return 0;
}
