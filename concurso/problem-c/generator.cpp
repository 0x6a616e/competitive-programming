#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cout << 2 << endl;
    {
        cout << 9999 << endl;
        int c = 0;
        for (int j = 1; j < 10000; ++j) {
            cout << to_string(j) << " " << c << " " << c + 99 << endl;
            c += 100;
        }
        cout << 999 << endl;
        c = 0;
        for (int j = 1; j < 1000; ++j) {
            cout << c + 100 << endl;
            c += 200;
        }
    }
    {
        cout << 9999 << endl;
        int c = 0;
        for (int j = 1; j < 10000; ++j) {
            cout << to_string(j) << " " << c << " " << c + 100 << endl;
            c += 50;
        }
        cout << 999 << endl;
        c = 0;
        for (int j = 1; j < 1000; ++j) {
            cout << ++c << endl;
        }
    }

    return 0;
}
