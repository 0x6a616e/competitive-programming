// https://codeforces.com/problemset/problem/1385/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int nums[n];

        for (int i = 0; i < n; ++i) cin >> nums[i];

        int status = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (status == 1 && nums[i] < nums[i + 1]) --status;
            if (status == 0 && nums[i] > nums[i + 1]) {
                --status;
                cout << i + 1 << '\n';
            }
        }
        if (status >= 0) cout << "0\n";
    }

    return 0;
}
