#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ull x, sol;
    cin >> x;
    sol = x;
    int count = 0;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            ++count;
            x /= i;
        }
        if (count % 2 == 1) sol *= i;
        count = 0;
    }
    if (x > 1) sol *= x;

    cout << sol << endl;

    return 0;
}
