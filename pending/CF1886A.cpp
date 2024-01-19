#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool posible = false;

        for (int x : {1, 2, 4, 5}) {
            for (int y : {1, 2, 4, 5}) {
                if (x == y) continue;
                int z = n - x - y;
                if (z <= 0) continue;
                if (z % 3 == 0) continue;
                if (x == z) continue;
                if (y == z) continue;
                posible = true;
                cout << "YES\n";
                cout << x << ' ' << y << ' ' << z << '\n';
                break;
            }
            if (posible) break;
        }

        if (!posible) cout << "NO\n";
    }

    return 0;
}
