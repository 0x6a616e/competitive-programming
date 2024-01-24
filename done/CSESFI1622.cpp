// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<string> sol;
    sort(s.begin(), s.end());

    do {
        sol.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << sol.size() << '\n';
    for (string &ss : sol) cout << ss << '\n';

    return 0;
}
