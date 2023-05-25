// https://codeforces.com/gym/104252/problem/E

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int d, int u) {
        int mejor = i + d + u;
        int i1, i2, d1, d2;

        for (i1 = 0; i1 <= i && mejor; i1++) {
                for (i2 = 0; i2 <= i - i1 && mejor; i2++) {
                        for (d1 = 0; d1 <= d && mejor; d1++) {
                                for (d2 = 0; d2 <= d - d1 && mejor; d2++) {
                                        if (i1 == u || i2 == u || d1 == u || d2 == u) {
                                                continue;
                                        }
                                        if (i2 && i2 == i1) {
                                                continue;
                                        }
                                        if (d1 && (d1 == i1 || d1 == i2)) {
                                                continue;
                                        }
                                        if (d2 && (d2 == i1 || d2 == i2 || d2 == d1)) {
                                                continue;
                                        }
                                        mejor = min(mejor, i - (i1 + i2) + d - (d1 + d2));
                                }
                        }
                }
        }
        return mejor;
}

int main()
{
        int N, K, E;

        cin >> N >> K >> E;

        cout << solve(E, N - K - E, K) << '\n';
        
        return 0;
}
