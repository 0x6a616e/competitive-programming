#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    map<int, map<int, int>> mapeo;
    mapeo[1][2] = 0;
    mapeo[1][4] = 0;
    mapeo[1][6] = 10;
    mapeo[1][8] = 0;

    mapeo[2][2] = 0;
    mapeo[2][4] = 0;
    mapeo[2][6] = 10;
    mapeo[2][8] = 0;

    mapeo[3][2] = 10;
    mapeo[3][4] = 10;
    mapeo[3][6] = 0;
    mapeo[3][8] = 10;

    mapeo[4][2] = 20;
    mapeo[4][4] = 0;
    mapeo[4][6] = 10;
    mapeo[4][8] = 0;

    mapeo[6][2] = 10;
    mapeo[6][4] = 10;
    mapeo[6][6] = 0;
    mapeo[6][8] = 10;

    mapeo[7][2] = 30;
    mapeo[7][4] = 10;
    mapeo[7][6] = 20;
    mapeo[7][8] = 10;

    mapeo[8][2] = 20;
    mapeo[8][4] = 20;
    mapeo[8][6] = 10;
    mapeo[8][8] = 0;

    mapeo[9][2] = 30;
    mapeo[9][4] = 30;
    mapeo[9][6] = 20;
    mapeo[9][8] = 10;

    while (t--) {
        int n;
        cin >> n;
        int lastFive = -1;
        int lastZero = -1;
        int nums[n];

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (nums[i] % 10 == 5) lastFive = nums[i];
            if (nums[i] % 10 == 0) lastZero = nums[i];
        }

        int sol[4] = {2, 4, 6, 8};
        int keep = 15;
        if (lastFive != -1) {
            for (int &i : nums)
                if (i != lastFive && i != (lastFive + 5)) keep = 0;
        } else if (lastZero != -1) {
            for (int &i : nums)
                if (i != lastZero && i != (lastZero - 5)) keep = 0;
        } else {
            int izq, izq_l, der_l, der;
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < 4; ++j) {
                    izq_l = nums[i - 1] % 10;
                    izq = (nums[i - 1] - izq_l) + sol[j] + mapeo[izq_l][sol[j]];

                    der_l = nums[i] % 10;
                    der = (nums[i] - der_l) + sol[j] + mapeo[der_l][sol[j]];

                    if (abs(izq - der) % 20 != 0) keep &= ~(1 << j);
                }
            }
        }

        if (keep == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
