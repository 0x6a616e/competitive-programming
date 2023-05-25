// https://codeforces.com/gym/104252/problem/M

#include <bits/stdc++.h>

using namespace std;

string move(string bolt, char movement) {
        if (movement == 'r') {
                return bolt.back() + bolt.substr(0, bolt.size() - 1);
        }
        if (movement == 'l') {
                return bolt.substr(1) + bolt[0];
        }
        if (movement == 'f') {
                reverse(bolt.begin(), bolt.end());
                return bolt;
        }
}

bool posible(string bolt, string fila, char movement) {
        // cout << bolt << " -> " << movement << " -> " << fila << ' ';
        bool sePuede = true;
        if (movement == 'r' || movement == 'l') {
                bolt = move(bolt, movement);
        }
        for (int i = 0; i < bolt.size() && sePuede; i++) {
                if (bolt[i] == '1' && fila[i] == '1') {
                        sePuede = false;
                }
        }
        // cout << sePuede << '\n';
        return sePuede;
}

int solve(string bolt, vector<string> &maze, vector<vector<int>> &memo, int ar, int ac) {
        if (ar == maze.size()) {
                memo[ar][ac] = 1;
        }
        if (memo[ar][ac] == -1) {
                memo[ar][ac] = 0;
                for (char i: { 'u', 'r', 'd', 'l' }) {
                        if (i == 'u' && ar == 0) {
                                continue;
                        }
                        if (i == 'u' && (ar == 1 || posible(bolt, maze[ar - 2], i))) {
                                memo[ar][ac] = max(memo[ar][ac], solve(bolt, maze, memo, ar - 1, ac));
                        }
                        if (i == 'r' && (!ar || posible(bolt, maze[ar - 1], i))) {
                                memo[ar][ac] = max(memo[ar][ac], solve(move(bolt, i), maze, memo, ar, (ac + 1) % maze[0].size()));
                        }
                        if (i == 'd' && posible(bolt, maze[ar], i)) {
                                memo[ar][ac] = max(memo[ar][ac], solve(bolt, maze, memo, ar + 1, ac));
                        }
                        if (i == 'l' && (!ar || posible(bolt, maze[ar - 1], i))) {
                                memo[ar][ac] = max(memo[ar][ac], solve(move(bolt, i), maze, memo, ar, (ac - 1 < 0 ? maze[0].size() - ac + 1 : ac - 1)));
                        }
                }
        }
        return memo[ar][ac];
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int R, C, ar, ac;
        string bolt;
        vector<string> maze;
        vector<vector<int>> memo;

        cin >> R >> C;

        maze.resize(R);
        memo.resize(R + 3, vector<int> (C + 3, -1));

        cin >> bolt;

        for (int i = 0; i < R; i++) {
                cin >> maze[i];
        }

        ar = 0;
        ac = 0;

        if (solve(bolt, maze, memo, ar, ac)) {
                cout << "Y\n";
        } else {
                memo.clear();
                memo.resize(R + 3, vector<int> (C + 3, -1));
                ar = 0;
                ac = 0;
                if (solve(move(bolt, 'f'), maze, memo, ar, ac)) {
                        cout << "Y\n";
                } else {
                        cout << "N\n";
                }
        }

        return 0;
}
