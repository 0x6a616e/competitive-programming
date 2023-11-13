#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int n = (int)s.size();

    map<char, int> frequencies;
    int odds = 0;

    for (char &c : s) {
        if (frequencies[c] % 2 == 0) ++odds;
        if (frequencies[c] % 2 != 0) --odds;
        ++frequencies[c];
    }

    bool sol = odds < 2;
    if (sol) {
        char c = 'A';
        int i = 0;
        while (c <= 'Z') {
            if (frequencies[c] && frequencies[c] % 2 == 0) {
                s[i] = s[n - 1 - i] = c;
                frequencies[c] -= 2;
                ++i;
            } else if (frequencies[c] % 2 != 0) {
                s[n / 2] = c;
                --frequencies[c];
            } else {
                ++c;
            }
        }

        cout << s << '\n';
    } else {
        cout << "NO SOLUTION\n";
    }

    return 0;
}
