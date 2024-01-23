// https://cses.fi/problemset/task/2165/

#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

void hanoi(vector<ii> &sol, int disks, int current, int destination) {
    if (disks == 1) {
        sol.push_back(make_pair(current, destination));
        return;
    }

    int aux = current ^ destination;
    hanoi(sol, disks - 1, current, aux);
    hanoi(sol, 1, current, destination);
    hanoi(sol, disks - 1, aux, destination);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> sol;
    hanoi(sol, n, 1, 3);

    cout << sol.size() << '\n';
    for (pair<int, int> &p : sol) cout << p.first << ' ' << p.second << '\n';

    return 0;
}
