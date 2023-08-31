#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cout << char('a' + (i % k));
        cout << '\n';
    }
    return 0;
}
