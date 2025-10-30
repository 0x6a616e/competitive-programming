#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    int case_n = 0;
    while (cin >> n) {
        int low = 2e6;
        int high = -2e6;
        int range = 0;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            low = min(low, x);
            high = max(high, x);
        }
        range = high - low;
        cout << "Case " << ++case_n << ": " << low << " " << high << " " << range << '\n';
    }

    return 0;
}
