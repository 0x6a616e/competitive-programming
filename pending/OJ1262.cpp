#include <bits/stdc++.h>

using namespace std;

void solve(vector<string> &s1, vector<set<char>> &s2, int &curr,
           string &attempt, int &k) {
    int i = (int)attempt.size();
    if (i == 5) {
        ++curr;
        if (curr == k) cout << attempt << '\n';
    } else if (i < 5) {
        char ca = '1';
        for (char &c : s1[i]) {
            if (ca == c) continue;
            ca = c;
            if (s2[i].count(c)) {
                attempt.push_back(c);
                solve(s1, s2, curr, attempt, k);
                attempt.pop_back();
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        vector<string> s1(5, "");
        for (int i = 0; i < 6; ++i) {
            string linea;
            cin >> linea;
            for (int j = 0; j < 5; ++j) s1[j] += linea[j];
        }
        for (string &s : s1) sort(s.begin(), s.end());
        vector<set<char>> s2(5);
        for (int i = 0; i < 6; ++i) {
            string linea;
            cin >> linea;
            for (int j = 0; j < 5; ++j) s2[j].insert(linea[j]);
        }
        int curr = 0;
        string attempt = "";
        solve(s1, s2, curr, attempt, k);

        if (curr < k) cout << "NO\n";
    }

    return 0;
}
