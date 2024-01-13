#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> found(n + 1);
    vector<int> a;
    a.reserve(n);

    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.push_back(ai);
        if (ai <= n) found[ai] = true;
    }

    queue<int> missing;
    for (int i = 1; i <= n; ++i) {
        if (!found[i]) missing.push(i);
        found[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        if (a[i] > n || found[a[i]]) {
            cout << missing.front();
            found[missing.front()] = true;
            missing.pop();
        } else {
            cout << a[i];
            found[a[i]] = true;
        }
    }

    return 0;
}
