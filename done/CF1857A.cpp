#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, num;
        cin >> n;

        int cp = 0;
        int ci = 0;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (num % 2 == 0)
                ++cp;
            else
                ++ci;
        }

        bool posible = false;

        if (ci % 2 == 0 || (ci % 2 == 0 && cp % 2 == 0)) posible = true;

        if (posible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
