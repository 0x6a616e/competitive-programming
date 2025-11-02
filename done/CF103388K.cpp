#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, d, m;
    cin >> t >> d >> m;
    int prev = 0;
    bool ans = false;
    for (int i = 0; i < m; ++i) {
        int curr;
        cin >> curr;
        if (curr - prev >= t) {
            ans = true;
        }
        prev = curr;
    }
    if (d - prev >= t) {
        ans = true;
    }
    cout << (ans ? "Y" : "N") << endl;

    return 0;
}
