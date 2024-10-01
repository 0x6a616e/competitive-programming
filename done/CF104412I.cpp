#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    unsigned long long n, m, k;
    cin >> n >> m >> k;

    int required = m * k;
    if (n >= required)
        cout << "Iron fist Ketil\n";
    else
        cout << "King Canute\n";

    return 0;
}
