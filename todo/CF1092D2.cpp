#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int solve(vector<long long> &walls, int i) {
        if ((i > 0 && walls[i - 1] == walls[i]) || (i < walls.size() - 1 && walls[i] == walls[i + 1])) {
                return 1;
        } else {
                if (memo[i] == 0) {
                        memo[i] = -1;
                        if (i > 0 && walls[i] > walls[i - 1]) {
                                memo[i] = max(memo[i], solve(walls, i - 1));
                        }
                        if (i < walls.size() - 1 && walls[i] > walls[i + 1]) {
                                memo[i] = max(memo[i], solve(walls, i + 1));
                        }
                }
                return memo[i];
        }
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;
        long long maximo = 0;

        cin >> n;

        vector<long long> walls(n);
        vector<bool> walls_b(n);
        memo.resize(n);

        for (int i = 0; i < n; i++) {
                cin >> walls[i];
                maximo = max(maximo, walls[i]);
        }

        bool sol = true;
        for (int i = 0; i < n && sol; i++) {
                sol = false;
                if (walls[i] == maximo) {
                        sol = true;
                }
                if (solve(walls, i) == 1) {
                        sol = true;
                }
        }

        if (sol) {
                cout << "YES\n";
        } else {
                cout << "NO\n";
        }

        return 0;
}
