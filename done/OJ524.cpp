#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &ring, int n, unordered_set<int> &primos) {
    if (ring.size() == n && primos.count(ring[0] + ring.back())) {
        for (int i = 0; i < n; ++i) cout << (i ? " " : "") << ring[i];
        cout << '\n';
    } else if (ring.size() < n) {
        for (int i = 2; i <= n; ++i) {
            if (primos.count(ring.back() + i)) {
                bool existe = false;
                for (int &j : ring)
                    if (i == j) existe = true;
                if (!existe) {
                    ring.push_back(i);
                    solve(ring, n, primos);
                    ring.pop_back();
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    unordered_set<int> primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n;
    int c = 0;
    while (cin >> n) {
        vector<int> ring;
        ring.reserve(n);
        ring.push_back(1);
        if (c) cout << "\n";
        cout << "Case " << ++c << ":\n";
        solve(ring, n, primos);
    }

    return 0;
}
