// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int ki;
    multiset<int> uniques;
    for (int i = 0; i < n; ++i) {
        cin >> ki;
        auto it = uniques.upper_bound(ki);
        if (it != uniques.end()) {
            uniques.erase(it);
        }
        uniques.insert(ki);
    }

    cout << uniques.size() << '\n';

    return 0;
}
