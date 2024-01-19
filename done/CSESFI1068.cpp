// https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    unsigned long long n;
    cin >> n;

    while (n != 1) {
        cout << n << ' ';
        if (n % 2)
            n = n * 3 + 1;
        else
            n = n / 2;
    }
    cout << n << endl;

    return 0;
}
