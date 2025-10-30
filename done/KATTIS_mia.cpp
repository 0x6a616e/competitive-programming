#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a0, a1, b0, b1;
    while (cin >> a0 >> a1 >> b0 >> b1) {
        if (a0 + a1 + b0 + b1 == 0) {
            break;
        }
        if (a1 > a0) {
            swap(a0, a1);
        }
        if (b1 > b0) {
            swap(b0, b1);
        }
        int a = a0 * 10 + a1;
        int b = b0 * 10 + b1;
        if (a == b) {
            cout << "Tie.\n";
        } else if (a == 21) {
            cout << "Player 1 wins.\n";
        } else if (b == 21) {
            cout << "Player 2 wins.\n";
        } else if (a0 == a1 && b0 == b1) {
            if (a > b) {
                cout << "Player 1 wins.\n";
            } else {
                cout << "Player 2 wins.\n";
            }
        } else if (a0 == a1) {
            cout << "Player 1 wins.\n";
        } else if (b0 == b1) {
            cout << "Player 2 wins.\n";
        } else {
            if (a > b) {
                cout << "Player 1 wins.\n";
            } else {
                cout << "Player 2 wins.\n";
            }
        }
    }

    return 0;
}
