#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        vector<int> ans;
        int u = n[(int)n.size() - 1] - '0';
        if (u % 2 == 0) ans.push_back(2);
        int acum = 0;
        for (char &c : n) acum += (c - '0');
        if (acum % 3 == 0) ans.push_back(3);
        int d = 0;
        if (n.size() > 1) d = n[(int)n.size() - 2] - '0';
        if ((d * 10 + u) % 4 == 0) ans.push_back(4);
        if (u % 5 == 0) ans.push_back(5);
        if (u % 2 == 0 && acum % 3 == 0) ans.push_back(6);
        if (ans.empty()) ans.push_back(-1);
        for (int i = 0; i < (int)ans.size(); ++i) cout << (i ? " " : "") << ans[i];
        cout << '\n';
    }

    return 0;
}
