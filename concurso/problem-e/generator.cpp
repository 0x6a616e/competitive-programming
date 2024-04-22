#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 100000;
    int m = 100000;

    cout << n << " " << m << endl;
    cout << 1;
    for (int i = 1; i < n; ++i) {
        cout << " " << (i % 1000) + 1;
    }
    cout << endl;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << i + 1 << " " << j + 1 << endl;
        }
    }

    return 0;
}
