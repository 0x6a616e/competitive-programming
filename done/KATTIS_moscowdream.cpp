#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a && b && c && n >= 3 && (a + b + c >= n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
