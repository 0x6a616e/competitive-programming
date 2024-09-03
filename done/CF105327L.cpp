#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> counter(32, 0);

    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!nums[j]) continue;
            if (nums[j] & 1) ++counter[i];
            nums[j] >>= 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        int curr = 0;
        for (int j = 0; j < 32; ++j) {
            int val = (1 << j);
            if (counter[j]) {
                --counter[j];
                curr += val;
            }
        }
        cout << (i == 0 ? "" : " ") << curr;
    }
    cout << endl;

    return 0;
}
