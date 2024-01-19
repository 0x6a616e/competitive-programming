// https://codeforces.com/gym/104555/problem/I

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, num;
    cin >> n;
    int pares = 0;
    int inpares = 0;

    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num == 1) swap(pares, inpares);
        if (num == 1) ++inpares;
        if (num == 0) ++pares;
        sol += inpares;
    }

    cout << sol << endl;

    return 0;
}
