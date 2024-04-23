// https://codeforces.com/gym/103960/problem/E

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, int> darts;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        if (darts[d + 1])
            --darts[d + 1];
        else
            ++sol;
        ++darts[d];
    }

    cout << sol << endl;

    return 0;
}
