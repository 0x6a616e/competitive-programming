// https://codeforces.com/gym/103940/problem/H

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N;
        long long X, contador, a;
        vector<bool> funny;

        cin >> N >> X;

        contador = 0;
        funny.resize(X + 1);

        for (int i = 0; i < N; i++) {
                cin >> a;
                for (long long j = 1; a * j <= X; j++) {
                        if (!funny[a * j]) {
                                contador++;
                        }
                        funny[a * j] = true;
                }
        }

        cout << contador << '\n';

        return 0;
}
