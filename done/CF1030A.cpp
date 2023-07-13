// https://codeforces.com/problemset/problem/1030/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, ni;

    cin >> n;

    while (n--) {
        cin >> ni;
        if (ni) {
            cout << "HARD\n";
            return 0;
        }
    }

    cout << "EASY\n";

    return 0;
}
