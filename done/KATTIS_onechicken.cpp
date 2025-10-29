#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    if (n > m) {
        if (n - m == 1) {
            cout << "Dr. Chaz needs " << n - m << " more piece of chicken!\n";
        } else {
            cout << "Dr. Chaz needs " << n - m << " more pieces of chicken!\n";
        }
    } else {
        if (m - n == 1) {
            cout << "Dr. Chaz will have " << m - n << " piece of chicken left over!\n";
        } else {
            cout << "Dr. Chaz will have " << m - n << " pieces of chicken left over!\n";
        }
    }

    return 0;
}
