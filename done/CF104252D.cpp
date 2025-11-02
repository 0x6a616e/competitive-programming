#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, h, w;
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;

        char ans1, ans2;
        ans1 = ans2 = 'N';
        if (a == 'Y' || w == 0) {
            ans1 = 'Y';
            --h;
            ++w;
        }
        if (b == 'Y' || h == 0) {
            ans2 = 'Y';
            --w;
            ++h;
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}
