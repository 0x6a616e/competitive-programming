#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        int b = 0;
        int r = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'B') {
                ++b;
            } else if (s[i] == 'R') {
                ++r;
                if (r > b) {
                    while (i < (int)s.size() && s[i] == 'R') ++i;
                    --i;
                    ans = i + 1;
                    b = r = 0;
                }
            }
        }
        if (r > b) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}
