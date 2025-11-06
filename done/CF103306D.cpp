#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int c, r, s;
        cin >> c >> r >> s;
        int maximum = c / s;
        int minimum = max(0, (c + r + s - 1) / s - r);
        cout << maximum << ' ' << minimum << '\n';
    }

    return 0;
}
