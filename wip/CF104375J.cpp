// https://codeforces.com/gym/104375/problem/J

#include <bits/stdc++.h>

using namespace std;

unsigned long long modulo = pow(10, 9) + 7;
vector<unsigned long long> A, sumas, sumas_2;

unsigned long long solve(int L, int R) {
        unsigned long long res;
        res = pow((sumas[R] - (L == 0 ? 0 : sumas[L - 1])), 2);
        res -= (sumas_2[R] - (L == 0 ? 0 : sumas_2[L - 1]));
        return res / 2;
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N, Q, L, R;

        cin >> N >> Q;

        A.resize(N);
        sumas.resize(N);
        sumas_2.resize(N);

        for (int i = 0; i < N; i++) {
                cin >> A[i];
                if (i == 0) {
                        sumas[i] = A[i];
                        sumas_2[i] = A[i] * A[i];
                } else {
                        sumas[i] = sumas[i - 1] + A[i];
                        sumas_2[i] = sumas_2[i - 1] + A[i] * A[i];
                }
        }

        while (Q--) {
                cin >> L >> R;
                cout << solve(L - 1, R - 1) % modulo << '\n';
        }

        return 0;
}
