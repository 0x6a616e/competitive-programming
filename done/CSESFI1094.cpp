#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    int best = 0;

    cin >> n;
    cin >> x;
    best = x;

    unsigned long long sol = 0;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x < best) sol += best - x;
        best = max(best, x);
    }

    cout << sol << endl;

    return 0;
}
