#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int an = 0;
    int bn = 0;
    for (int i = 0, c = 100; i < 3; ++i) {
        an += (a[i] - '0') * c;
        bn += (b[i] - '0') * c;
        c /= 10;
    }

    if (bn > an) {
        swap(a, b);
    }

    cout << a << '\n';

    return 0;
}
