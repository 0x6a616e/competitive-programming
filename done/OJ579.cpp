#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie();
        ios::sync_with_stdio(0);

        int h, m;
        double sol;
        char b;

        while (cin >> h >> b >> m && (h || m)) {
                sol = abs(30 * h + (m / 2.0) - 6 * m);

                if (sol > 180) {
                        sol = 360 - sol;
                }

                cout << fixed << setprecision(3) << sol << '\n';
        }
        
        return 0;
}
