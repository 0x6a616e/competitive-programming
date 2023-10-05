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

        int sol[2] = {0, 0};
        int turno[4] = {0, 0, 1, 1};

        int curr = 1;
        int turnoActual = 1;

        while (n) {
            sol[turno[turnoActual]] += min(curr, n);
            n = max(0, n - curr);
            ++curr;
            turnoActual = (turnoActual + 1) % 4;
        }

        cout << sol[0] << ' ' << sol[1] << '\n';
    }

    return 0;
}
