#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    list<int> l = {1};
    auto it = l.begin();
    int c = 2;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        if (s[i] == 'l') {
            l.emplace(it, c++);
            advance(it, -1);
        } else {
            l.emplace(next(it), c++);
            advance(it, 1);
        }
    }
    for (it = l.begin(); it != l.end(); advance(it, 1)) {
        cout << *it << '\n';
    }

    return 0;
}
