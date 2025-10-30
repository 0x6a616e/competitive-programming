#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string prev;
    cin >> prev;
    --n;
    bool asc = true;
    bool desc = true;
    while (n--) {
        string curr;
        cin >> curr;
        if (curr > prev) {
            desc = false;
        }
        if (curr < prev) {
            asc = false;
        }
        prev = curr;
    }

    if (desc) {
        cout << "DECREASING\n";
    } else if (asc) {
        cout << "INCREASING\n";
    } else {
        cout << "NEITHER\n";
    }

    return 0;
}
