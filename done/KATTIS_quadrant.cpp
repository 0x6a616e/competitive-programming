#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, y;
    cin >> x >> y;

    if (x > 0) {
        if (y > 0) {
            cout << "1\n";
        } else {
            cout << "4\n";
        }
    } else {
        if (y > 0) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }

    return 0;
}
