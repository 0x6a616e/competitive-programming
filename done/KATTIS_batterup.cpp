#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int acum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (b == -1) {
            continue;
        }
        acum += b;
        ++count;
    }

    cout << fixed << setprecision(6) << (double)acum / count << '\n';

    return 0;
}
