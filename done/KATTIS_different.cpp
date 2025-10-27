#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long a, b;
    while (cin >> a >> b) {
        if (b < a) swap(a, b);
        cout << b - a << '\n';
    }

    return 0;
}
