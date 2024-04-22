#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10000;
    cout << n << endl;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cout << (c % 400) + 100;
        ++c;
        cout << " " << (c % 400) + 100;
        ++c;
        cout << " " << (c % 400) + 100;
        ++c;
        cout << " " << (c % 400) + 100;
        ++c;
        cout << " " << (c % 400) + 100;
        ++c;
        cout << endl;
    }
    cout << 0 << endl;

    return 0;
}
