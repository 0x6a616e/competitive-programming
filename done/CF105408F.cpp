#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a = 0;
    int b = 0;
    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < 4; ++i) {
        int x;
        cin >> x;
        b += x;
    }
    cout << a - b << endl;

    return 0;
}
