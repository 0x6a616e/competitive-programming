#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << x << " is " << (x % 2 == 0 ? "even" : "odd") << '\n';
    }

    return 0;
}
