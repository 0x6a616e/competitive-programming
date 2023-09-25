#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

    int c = 0;
    do {
        cout << ++c << ": ";
        for (int &i : nums) cout << i << ' ';
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
