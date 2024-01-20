// https://codeforces.com/contest/1536/problem/B

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

        string s;
        cin >> s;

        string sol = "a";
        bool searching = true;

        while (searching) {
            size_t found = s.find(sol);
            if (found == string::npos) {
                searching = false;
                break;
            }
            ++sol.back();
            for (size_t i = sol.size(); i > 0; --i) {
                if (sol[i] > 'z') {
                    sol[i] = 'a';
                    ++sol[i - 1];
                }
            }
            if (sol[0] > 'z') sol = string(sol.size() + 1, 'a');
        }

        cout << sol << '\n';
    }

    return 0;
}
