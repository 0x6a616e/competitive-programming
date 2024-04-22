#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, n;
    cin >> x >> n;
    set<int> borders = {0, x};
    map<int, int> distances;
    ++distances[x];

    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        auto it = borders.upper_bound(pi);
        int upper = *it;
        --it;
        int lower = *it;
        --distances[upper - lower];
        if (distances[upper - lower] == 0) distances.erase(upper - lower);
        ++distances[pi - lower];
        ++distances[upper - pi];
        borders.insert(pi);
        auto it2 = distances.end();
        --it2;
        cout << it2->first << '\n';
    }

    return 0;
}
