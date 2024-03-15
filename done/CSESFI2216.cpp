// https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    set<int> curr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        curr.erase(x);
        curr.insert(x + 1);
    }
    cout << curr.size() << '\n';

    return 0;
}
