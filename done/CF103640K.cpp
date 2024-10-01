#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> count(26);
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        count[words[i][0] - 'A'] = true;
    }

    bool possible = false;
    for (string word : words) {
        bool local_possible = true;
        for (char c : word) local_possible = local_possible && count[c - 'A'];
        possible = possible || local_possible;
        if (possible) break;
    }

    if (possible)
        cout << "Y\n";
    else
        cout << "N\n";

    return 0;
}
