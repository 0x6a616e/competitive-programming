// https://codeforces.com/problemset/problem/915/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;

    int sol = 0;
    if (l > 1) ++sol;
    if (r < n) ++sol;

    if (pos < l) {
        sol += l - pos;
        pos = l;
    } else if (pos > r) {
        sol += pos - r;
        pos = r;
    } else if (pos > l && pos < r) {
        if (l > 1 && r < n) {
            if (abs(l - pos) <= abs(r - pos)) {
                sol += pos - l;
                pos = l;
            } else {
                sol += r - pos;
                pos = r;
            }
        } else if (l > 1) {
            sol += pos - l;
            pos = l;
        } else if (r < n) {
            sol += r - pos;
            pos = r;
        }
    }

    if (pos == l && r < n) sol += r - l;
    if (pos == r && l > 1) sol += r - l;

    cout << sol << endl;

    return 0;
}
