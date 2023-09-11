#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int nums[n];
        for (int i = 0; i < n; ++i) cin >> nums[i];
        sort(nums, nums + n);
        int mayor = -1;
        int curr = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] != curr++ && mayor == -1) mayor = curr - 1;

        if (mayor == -1) mayor = n;

        cout << mayor << '\n';
        int y;
        while (true) {
            cin >> y;
            if (y == -1) break;
            if (y == -2) break;
            cout << y << '\n';
        }
    }

    return 0;
}
