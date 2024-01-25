#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    long long a, b;
    long long best = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        a = b = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                a += p[i];
            } else {
                b += p[i];
            }
        }
        if (b > a) swap(a, b);
        if (best == -1) best = a - b;
        best = min(best, a - b);
    }

    cout << best << endl;

    return 0;
}
