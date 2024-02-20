// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> a, b;
    int ai, bi;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a.push(ai);
    }
    for (int i = 0; i < m; i++) {
        cin >> bi;
        b.push(bi);
    }

    int sol = 0;
    while (!a.empty() && !b.empty()) {
        if (abs(a.top() - b.top()) <= k) {
            a.pop();
            b.pop();
            ++sol;
        } else if (a.top() > b.top()) {
            a.pop();
        } else {
            b.pop();
        }
    }

    cout << sol << '\n';

    return 0;
}
