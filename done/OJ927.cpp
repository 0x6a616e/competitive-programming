#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    cin >> c;

    while (c--) {
        int grade;
        cin >> grade;

        vector<int> coeficientes(grade + 1);
        for (int i = 0; i <= grade; ++i) cin >> coeficientes[i];

        int d, k;
        cin >> d;
        cin >> k;

        int curr = 0;
        int n = 1;
        while (k > curr) {
            curr += d * n;
            ++n;
        }
        --n;

        long long res = 0;
        for (int i = 0; i <= grade; ++i) {
            res += coeficientes[i] * pow(n, i);
        }

        cout << res << '\n';
    }

    return 0;
}
