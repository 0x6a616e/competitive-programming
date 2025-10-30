#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if (t == 1) {
        cout << "7\n";
    } else if (t == 2) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            cout << "Bigger\n";
        } else if (a == b) {
            cout << "Equal\n";
        } else {
            cout << "Smaller\n";
        }
    } else if (t == 3) {
        array<int, 3> a;
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        cout << a[1] << '\n';
    } else if (t == 4) {
        long long acum = 0;
        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai;
            acum += ai;
        }
        cout << acum << '\n';
    } else if (t == 5) {
        long long acum = 0;
        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai;
            if (ai % 2 == 0) {
                acum += ai;
            }
        }
        cout << acum << '\n';
    } else if (t == 6) {
        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai;
            cout << (char)('a' + (ai % 26));
        }
        cout << '\n';
    } else if (t == 7) {
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        int i = 0;
        int temp;
        while (true) {
            temp = a[i];
            a[i] = -1;
            i = temp;
            if (i >= n) {
                cout << "Out\n";
                break;
            }
            if (i == n - 1) {
                cout << "Done\n";
                break;
            }
            if (i == -1) {
                cout << "Cyclic\n";
                break;
            }
        }
    }
}
