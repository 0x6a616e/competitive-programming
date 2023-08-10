#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int caso = 0;

    while (cin >> n && n) {
        cout << "Case " << ++caso << ":\n";
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        int q;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            long long query;
            cin >> query;

            long long mejor = 1000000;
            int curr;
            for (int j = 0; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    curr = nums[j] + nums[k];
                    if (abs(curr - query) < abs(mejor - query)) {
                        mejor = curr;
                    }
                }
            }

            cout << "Closest sum to " << query << " is " << mejor << ".\n";
        }
    }

    return 0;
}
