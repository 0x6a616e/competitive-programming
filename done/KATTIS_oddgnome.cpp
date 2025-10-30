#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int g;
        cin >> g;
        int curr;
        cin >> curr;
        int sol = -1;
        for (int i = 1; i < g; ++i) {
            int gi;
            cin >> gi;
            if (sol == -1 && gi != curr + i) {
                sol = i + 1;
            }
        }
        cout << sol << '\n';
    }

    return 0;
}
