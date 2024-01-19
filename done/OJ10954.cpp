#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    while (cin >> n && n) {
        int num;
        priority_queue<int, vector<int>, greater<int>> pending;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            pending.push(num);
        }

        int cost = 0;
        int n1, n2;

        while (pending.size() > 1) {
            n1 = pending.top();
            pending.pop();

            n2 = pending.top();
            pending.pop();

            pending.push(n1 + n2);
            cost += (n1 + n2);
        }

        cout << cost << '\n';
    }

    return 0;
}
