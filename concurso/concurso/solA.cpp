#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        vector<int> runners(n);
        for (int i = 0; i < n; ++i) cin >> runners[i];
        sort(runners.begin(), runners.end());
        if (n == 1) {
            cout << runners[0] << '\n';
            cout << runners[0] << '\n';
        } else if (n == 2) {
            cout << runners[1] << '\n';
            cout << runners[0] << ' ' << runners[1] << '\n';
        } else {
            priority_queue<int> faster;
            faster.push(runners[0]);
            faster.push(runners[1]);
            vector<vector<int>> sol;
            int time = 0;
        }
    }

    return 0;
}
