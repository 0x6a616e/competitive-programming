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

        int totalB = (n + 2 - 1) / 2;
        int totalN = n / 2;

        int turnos[4] = {0, 0, 1, 1};
        int turno = 1;

        int sol[2][2] = {{0, 0}, {0, 0}};

        int lotes[2] = {0, 0};
        int turnoL = 1;

        while (totalB || totalN) {
            ++lotes[turnos[turnoL]];
            turnoL = (turnoL + 1) % 4;

            sol[turnos[turno]][0] += min(totalB, lotes[0]);
            totalB = max(0, totalB - lotes[0]);

            sol[turnos[turno]][1] += min(totalN, lotes[1]);
            totalN = max(0, totalN - lotes[1]);

            turno = (turno + 1) % 4;
        }

        cout << sol[0][0] << ' ' << sol[0][1] << ' ' << sol[1][0] << ' '
             << sol[1][1] << '\n';
    }

    return 0;
}
