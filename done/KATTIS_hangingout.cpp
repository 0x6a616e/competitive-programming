#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, x;
    cin >> l >> x;
    int curr = 0;
    int ans = 0;
    while (x--) {
        string op;
        int p;
        cin >> op >> p;
        if (op == "enter") {
            if (curr + p <= l) {
                curr += p;
            } else {
                ++ans;
            }
        } else {
            curr -= p;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
