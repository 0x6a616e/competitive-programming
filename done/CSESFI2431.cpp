#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    int q, digits;
    unsigned long long k, curr, count;
    cin >> q;

    while (q--) {
        cin >> k;
        curr = 0;
        digits = 1;
        count = 9;

        while (curr + count * digits < k) {
            curr += count * digits;
            ++digits;
            count *= 10;
        }

        string s(digits, '0');
        count /= 9;

        for (int i = 0; i < digits; ++i) {
            int j = (i ? 0 : 1);
            for (; j <= 10; ++j) {
                if (curr + digits * count >= k) break;
                curr += digits * count;
            }
            count /= 10;
            s[i] = '0' + j;
        }

        ++curr;
        int sol = k - curr;
        cout << s[sol] << '\n';
    }

    return 0;
}
