// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    long long curr;
    long long best;
    long long sol;

    int x;
    cin >> x;
    curr = x;
    best = x;

    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (curr + x > x) {
            curr += x;
        } else {
            curr = x;
        }
        sol = curr;
        best = max(best, sol);
    }

    cout << best << '\n';

    return 0;
}
