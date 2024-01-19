#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, x, y, anillo, sentido, currY, currX;
    unsigned long long currVal;
    cin >> t;

    while (t--) {
        cin >> y >> x;
        anillo = max(x, y);
        currX = currY = anillo;
        currVal = 1LL * anillo * anillo - anillo + 1;
        sentido = 0;
        if (currY != y) {
            sentido = (anillo % 2 ? 1 : -1);
            currVal = currVal + sentido * abs(currY - y);
        } else if (currX != x) {
            sentido = (anillo % 2 ? -1 : 1);
            currVal = currVal + sentido * abs(currX - x);
        }

        cout << currVal << '\n';
    }

    return 0;
}
