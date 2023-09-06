#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int m;
    cin >> m;
    int nums[m];
    for (int i = 0; i < m; ++i) cin >> nums[i];
    sort(nums, nums + m, greater<int>());
    deque<int> sol;
    sol.push_back(nums[0]);
    for (int i = 1; i < m; ++i) {
        if (nums[i] < sol.back())
            sol.push_back(nums[i]);
        else if (nums[i] < sol.front())
            sol.push_front(nums[i]);
    }

    cout << sol.size() << endl;
    while (!sol.empty()) {
        cout << sol.front() << ' ';
        sol.pop_front();
    }
    cout << endl;

    return 0;
}
