#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> colors;
    vector<priority_queue<int, vector<int>, greater<int>>> pqs(k + 1);
    for (int i = 0; i < n; ++i) {
        int ni, ci;
        cin >> ni >> ci;
        colors.push_back(ci);
        pqs[ci].push(ni);
    }

    bool ans = true;
    int expected = 1;
    for (int &ci : colors) {
        if (!pqs[ci].empty() && pqs[ci].top() == expected) {
            ++expected;
            pqs[ci].pop();
        } else {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Y" : "N") << endl;

    return 0;
}
