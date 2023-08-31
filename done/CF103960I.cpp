#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    int c = 0;
    for (int i = 0; i < 8; ++i) {
        cin >> n;
        c += n;
    }
    if (c <= 8)
        cout << "S\n";
    else
        cout << "F\n";
    return 0;
}
