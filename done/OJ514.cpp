#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    while (cin >> n && n) {
        int num;
        vector<int> nums(n);

        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        while (cin >> num && num) {
            queue<int> perm;
            perm.push(num);

            for (int i = 1; i < n; ++i) {
                cin >> num;
                perm.push(num);
            }

            int nums_index = 0;
            stack<int> station;
            bool posible = true;

            while (posible && !perm.empty()) {
                if (!station.empty() && perm.front() == station.top()) {
                    perm.pop();
                    station.pop();
                } else if (nums_index < n && perm.front() == nums[nums_index]) {
                    perm.pop();
                    ++nums_index;
                } else if (nums_index < n) {
                    station.push(nums[nums_index]);
                    ++nums_index;
                } else {
                    posible = false;
                }
            }

            if (posible) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << '\n';
    }

    return 0;
}
