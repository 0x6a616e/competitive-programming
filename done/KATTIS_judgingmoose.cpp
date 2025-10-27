#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, r;
    cin >> l >> r;

    if (l == r) {
        if (l == 0) {
            cout << "Not a moose\n";
        } else {
            cout << "Even " << l + r << '\n';
        }
    } else {
        cout << "Odd " << max(l, r) * 2 << '\n';
    }

    return 0;
}
