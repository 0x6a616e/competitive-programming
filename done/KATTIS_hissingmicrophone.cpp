#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    string ans = "no ";
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 's' && s[i] == s[i - 1]) {
            ans = "";
        }
    }
    ans += "hiss\n";
    cout << ans;

    return 0;
}
