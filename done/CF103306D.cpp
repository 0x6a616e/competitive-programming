#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        long long c, r, s;
        cin >> c >> r >> s;
        long long total = (c + r + s - 1) / s;
        long long maximum = max(0LL, total - (r + s - 1) / s);
        long long minimum = max(0LL, total - r);
        cout << maximum << ' ' << minimum << '\n';
    }

    return 0;
}
