#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'R') {
            if (i + 2 < s.size() && ((s[i + 1] == 'B' && s[i + 2] == 'L') || (s[i + 1] == 'L' && s[i + 2] == 'B'))) {
                cout << 'C';
                i += 2;
            } else {
                cout << 'S';
            }
        } else if (s[i] == 'B') {
            if (i + 2 < s.size() && ((s[i + 1] == 'R' && s[i + 2] == 'L') || (s[i + 1] == 'L' && s[i + 2] == 'R'))) {
                cout << 'C';
                i += 2;
            } else {
                cout << 'K';
            }
        } else if (s[i] == 'L') {
            if (i + 2 < s.size() && ((s[i + 1] == 'B' && s[i + 2] == 'R') || (s[i + 1] == 'R' && s[i + 2] == 'B'))) {
                cout << 'C';
                i += 2;
            } else {
                cout << 'H';
            }
        }
    }
    cout << '\n';

    return 0;
}
