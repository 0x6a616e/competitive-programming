#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string num;
        int last_cleared;

        cin >> num;

        num = '0' + num;
        last_cleared = (int)num.size();

        for (int i = (int)num.size() - 1; i > 0; --i) {
            int d = num[i] - '0';
            if (d >= 5) {
                for (int j = i; j < (int)num.size() && j <= last_cleared; ++j)
                    num[j] = '0';
                last_cleared = i;
                if (num[i - 1] != '9') {
                    num[i - 1] = char('0' + num[i - 1] - '0' + 1);
                }
            }
        }

        if (num[0] != '0') cout << num[0];

        for (int i = 1; i < (int)num.size(); ++i) cout << num[i];

        cout << '\n';
    }

    return 0;
}
