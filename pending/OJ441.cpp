#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    bool caso = false;

    while (cin >> k && k) {
        if (caso) cout << '\n';
        caso = true;
        vector<int> S(k);
        for (int i = 0; i < k; ++i) cin >> S[i];

        for (int a = 0; a < k; ++a) {
            for (int b = a + 1; b < k; ++b) {
                for (int c = b + 1; c < k; ++c) {
                    for (int d = c + 1; d < k; ++d) {
                        for (int e = d + 1; e < k; ++e) {
                            for (int f = e + 1; f < k; ++f) {
                                cout << S[a] << ' ' << S[b] << ' ' << S[c]
                                     << ' ' << S[d] << ' ' << S[e] << ' '
                                     << S[f] << '\n';
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
