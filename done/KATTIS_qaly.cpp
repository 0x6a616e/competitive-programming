#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    double ans = 0;
    while (n--) {
        double q, y;
        cin >> q >> y;
        ans += q * y;
    }

    cout << ans << '\n';

    return 0;
}
