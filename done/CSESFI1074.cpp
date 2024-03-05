// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) cin >> sticks[i];
    sort(sticks.begin(), sticks.end());

    int target = sticks[(n + 1) / 2 - 1];
    long long int sol = 0;
    for (int stick : sticks) sol += abs(stick - target);

    cout << sol << '\n';

    return 0;
}
