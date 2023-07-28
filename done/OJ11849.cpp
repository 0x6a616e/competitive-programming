#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;

    while (cin >> n >> m && (n || m)) {
        unordered_set<int> appeared;
        int counter = 0;
        int disc;

        for (int i = 0; i < n; ++i) {
            cin >> disc;
            appeared.insert(disc);
        }
        for (int i = 0; i < m; ++i) {
            cin >> disc;
            if (appeared.count(disc)) {
                ++counter;
            }
        }
        cout << counter << '\n';
    }

    return 0;
}
