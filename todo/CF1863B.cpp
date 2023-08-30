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
        int izq = 0;
        int der = 0;

        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            if (num < i)
                der = max(der, abs(i - num));
            else if (num > i)
                izq = max(izq, abs(i - num));
        }
        if (n == 1)
            cout << "0\n";
        else if (n == 2)
            cout << "1\n";
        else
            cout << floor(log2(izq)) + floor(log2(der)) << '\n';
    }

    return 0;
}
