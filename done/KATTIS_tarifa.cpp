#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x;
    cin >> x;
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int p;
        cin >> p;
        ans += (x - p);
    }
    cout << ans + x << endl;

    return 0;
}
