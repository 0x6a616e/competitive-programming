// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    set<int> s;
    int curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        s.insert(curr);
    }
    cout << s.size() << "\n";

    return 0;
}
