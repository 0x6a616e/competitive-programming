// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    /*
     * 0 0 0
     * 0 0 1
     * 0 1 1
     * 0 1 0
     * 1 1 1
     * 1 1 0
     * 1 0 0
     * 1 0 1
     */
    vector<string> sol = {"0", "1"};
    while ((int)sol[0].size() < n) {
        int c = (int)sol.size();
        for (int i = c - 1; i >= 0; --i) sol.push_back(sol[i]);
        for (int i = 0; i < c; ++i) sol[i] = "0" + sol[i];
        for (int i = c; i < (int)sol.size(); ++i) sol[i] = "1" + sol[i];
    }

    for (string &s : sol) cout << s << '\n';

    return 0;
}
