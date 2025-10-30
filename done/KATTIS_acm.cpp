#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int m;
    int ans_c = 0;
    int ans_p = 0;
    vector<int> penalties(26, 0);
    while (cin >> m) {
        if (m == -1) {
            break;
        }
        char p;
        string res;
        cin >> p >> res;
        if (res == "right") {
            ++ans_c;
            ans_p += m + penalties[p - 'A'] * 20;
        } else {
            ++penalties[p - 'A'];
        }
    }

    cout << ans_c << ' ' << ans_p << '\n';

    return 0;
}
