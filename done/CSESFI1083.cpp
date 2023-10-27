#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> nums(n + 1);
    int c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> c;
        nums[c] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (!nums[i]) cout << i << endl;

    return 0;
}
