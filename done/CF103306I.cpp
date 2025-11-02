#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n >= 10) {
            int aux = n;
            int curr = 1;
            while (aux) {
                curr *= aux % 10;
                aux /= 10;
            }
            ++ans;
            n = curr;
        }
        cout << ans << '\n';
    }

    return 0;
}
