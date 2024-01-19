// https://codeforces.com/problemset/problem/1515/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n, l, r, c;
    cin >> t;

    while (t--) {
        int sol = 0;
        cin >> n >> l >> r;

        map<int, int> izq, der;
        for (int i = 0; i < l; ++i) {
            cin >> c;
            ++izq[c];
        }

        for (int i = 0; i < r; ++i) {
            cin >> c;
            if (izq[c])
                --izq[c];
            else
                ++der[c];
        }

        int diff = abs(l - r);
        if (diff) {
            map<int, int> curr = (l > r ? izq : der);
            map<int, int>::iterator it;
            for (it = curr.begin(); it != curr.end() && diff; ++it) {
                while (it->second >= 2 && diff) {
                    ++sol;
                    diff -= 2;
                    it->second -= 2;
                    if (l > r) izq[it->first] -= 2;
                    if (r > l) der[it->first] -= 2;
                }
            }
        }

        if (diff) {
            map<int, int> curr = (l > r ? izq : der);
            map<int, int>::iterator it;
            for (it = curr.begin(); it != curr.end() && diff; ++it) {
                while (it->second >= 1 && diff) {
                    ++sol;
                    diff -= 2;
                    --it->second;
                    if (l > r) {
                        --izq[it->first];
                        ++der[it->first];
                    } else {
                        --der[it->first];
                        ++izq[it->first];
                    }
                }
            }
        }

        map<int, int>::iterator it;
        for (it = izq.begin(); it != izq.end(); ++it) sol += it->second;

        cout << sol << '\n';
    }

    return 0;
}
