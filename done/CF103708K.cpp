// https://codeforces.com/gym/103708/problem/K

#include <bits/stdc++.h>

using namespace std;

vector<int> r, memo(50001, -1);

int solve(int cant) {
        if (cant <= 0) {
                return abs(cant);
        }
        if (memo[cant] == -1) {
                int minimo = 50000;
                for (int i = 0; i < r.size() && minimo ; i++) {
                        minimo = min(minimo, solve(cant - r[i]));
                }
                memo[cant] = minimo;
        }
        return memo[cant];
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int k, p, ki;

        cin >> k >> p;

        r.resize(p);
        
        for (int i = 0; i < p; i++) {
                cin >> r[i];
        }

        sort(r.begin(), r.end());

        while (k--) {
                cin >> ki;
                cout << solve(ki) << '\n';
        }

        return 0;
}
