#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int l = i + 1;
        int r = n - i;
        ans += (long long)l * r * k;
    }
    cout << ans << endl;

    return 0;
}
