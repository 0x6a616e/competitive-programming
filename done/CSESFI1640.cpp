// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (m.count(x - a[i])) {
            cout << m[x - a[i]] + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        m[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
