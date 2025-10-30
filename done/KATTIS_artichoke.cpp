#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;

    double ans = 0;
    double high = p * (sin(a + b) + cos(c + d) + 2);
    double curr;

    for (int i = 2; i <= n; ++i) {
        curr = p * (sin(a * i + b) + cos(c * i + d) + 2);
        ans = max(ans, high - curr);
        high = max(high, curr);
    }
    
    cout << fixed << setprecision(6) << ans << '\n';
    
    return 0;
}
