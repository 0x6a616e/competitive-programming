#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int sol = 0;
    long long curr = 5;
    while (curr <= n) {
        sol += n / curr;
        curr *= 5;
    }

    cout << sol << endl;

    return 0;
}
