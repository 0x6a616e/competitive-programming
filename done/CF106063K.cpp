#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long l = max(a, c);
        long long r = min(b, d);
        long long ans = max(0LL, r - l);
        cout << ans << '\n';
    }

    return 0;
}
