// https://codeforces.com/gym/104375/problem/G

#include <bits/stdc++.h>

using namespace std;

vector<vector<short int>> memo;

short int solve(int N, int turno) {
        if (!memo[N][turno]) {
                if (turno >= N) {
                        memo[N][turno] = (turno % 2 ? -1 : 1);
                } else {
                        if (turno % 2) {
                                short int minimo = 1;
                                for (short int i = turno; i >= 1 && minimo == 1; i--) {
                                        minimo = min(minimo, solve(N - i, turno + 1));
                                }
                                memo[N][turno] = minimo;
                        } else {
                                short int maximo = -1;
                                for (short int i = turno; i >= 1 && maximo == -1; i--) {
                                        maximo = max(maximo, solve(N - i, turno + 1));
                                }
                                memo[N][turno] = maximo;
                        }
                }
        }
        return memo[N][turno];
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N;
        cin >> N;

        memo.resize(N + 1, vector<short int> (N + 1, 0));

        if (solve(N, 1) == -1)
                cout << "Jane\n";
        else
                cout << "John\n";

        return 0;
}
