#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;

    cin >> a >> b >> c;

    int sol = 0;
    int curr = (a % b) * 10;
    set<int> known;
    while (!known.count(curr)) {
        ++sol;
        if (curr / b == c) break;
        known.insert(curr);
        curr = (curr % b) * 10;
    }

    if (curr / b == c)
        cout << sol << endl;
    else
        cout << "-1\n";

    return 0;
}
