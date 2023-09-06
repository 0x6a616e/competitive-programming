#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &angles, int index, int acum) {
    if (index == (int)angles.size()) return acum % 360 == 0;

    return solve(angles, index + 1, acum + angles[index]) ||
           solve(angles, index + 1, acum - angles[index]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> angles(n);
    for (int i = 0; i < n; ++i) cin >> angles[i];

    if (solve(angles, 0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
