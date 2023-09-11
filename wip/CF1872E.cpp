#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int nums[n];
        int acum_0 = 0;
        int acum_1 = 0;

        for (int i = 0; i < n; ++i) cin >> nums[i];

        string binary;
        cin >> binary;

        for (int i = 0; i < n; ++i) {
            if (binary[i] == '0') acum_0 ^= nums[i];
            if (binary[i] == '1') acum_1 ^= nums[i];
        }

        int q;
        cin >> q;

        int op, a, b;
        for (int i = 0; i < q; ++i) {
            cin >> op;
            if (op == 1) {
                cin >> a >> b;
                --a;
                for (int j = a; j < b; ++j) {
                    if (binary[j] == '0')
                        binary[j] = '1';
                    else if (binary[j] == '1')
                        binary[j] = '0';
                    acum_0 ^= nums[j];
                    acum_1 ^= nums[j];
                }
            } else if (op == 2) {
                cin >> a;
                if (a == 0) cout << acum_0 << ' ';
                if (a == 1) cout << acum_1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
