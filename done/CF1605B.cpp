// https://codeforces.com/problemset/problem/1605/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s = "";
        bool ordenado = true;
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if (i)
                if (c == '0' && s.back() == '1') ordenado = false;
            s += c;
        }
        int i_i = 0;
        int i_d = n - 1;
        vector<int> sol;
        sol.reserve(n);
        while (!ordenado && i_i < i_d) {
            if (s[i_i] == '0' && s[i_d] == '0') {
                ++i_i;
            } else if (s[i_i] == '0' && s[i_d] == '1') {
                ++i_i;
                --i_d;
            } else if (s[i_i] == '1' && s[i_d] == '0') {
                sol.push_back(i_i);
                sol.push_back(i_d);
                ++i_i;
                --i_d;
            } else if (s[i_i] == '1' && s[i_d] == '1') {
                --i_d;
            }
        }
        sort(sol.begin(), sol.end());
        cout << !sol.empty() << '\n';
        if (!sol.empty()) {
            cout << sol.size();
            for (int &i : sol) cout << ' ' << ++i;
            cout << '\n';
        }
    }

    return 0;
}
