#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<int> aparecidos;
    bool sol = false;
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        int p;
        for (int j = k - 1; j >= 0; --j) {
            cin >> p;
            curr += (p << j);
        }
        aparecidos.insert(curr);
        for (int j = 0; j < (1 << k); ++j)
            if ((curr & j) == 0 && aparecidos.count(j)) sol = true;
    }

    if (sol) cout << "YES\n";
    if (!sol) cout << "NO\n";

    return 0;
}
