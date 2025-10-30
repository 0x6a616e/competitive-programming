#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int acum = 0;
        int best = 0;
        int best_c = 0;
        int best_i = -1;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            acum += v;
            if (v > best) {
                best = v;
                best_c = 1;
                best_i = i + 1;
            } else if (v == best) {
                ++best_c;
            }
        }
        if (best_c > 1) {
            cout << "no winner\n";
        } else {
            if (best > acum / 2) {
                cout << "majority winner " << best_i << '\n';
            } else {
                cout << "minority winner " << best_i << '\n';
            }
        }
    }

    return 0;
}
