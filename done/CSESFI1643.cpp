// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    long long sol[n];
    long long curr = -10000000000000000;
    long long best = -10000000000000000;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (curr + x > x) {
            curr += x;
        } else {
            curr = x;
        }
        sol[i] = curr;
        best = max(best, sol[i]);
    }

    cout << best << '\n';

    return 0;
}
