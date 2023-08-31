#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << "YES\n";
        else if (x == 1)
            if (y == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        else if (x == 2)
            if (y == 1 || y == 3)
                cout << "YES\n";
            else
                cout << "NO\n";
        else if (x == 3)
            if (y < 4)
                cout << "YES\n";
            else
                cout << "NO\n";
        else if (x > 3)
            cout << "YES\n";
    }
    return 0;
}
