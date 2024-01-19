// https://codeforces.com/problemset/problem/385/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, c;
    cin >> n >> c;

    int past = 0;
    int mejor = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (i) mejor = max(mejor, past - num);
        past = num;
    }
    mejor = max(mejor - c, 0);
    cout << mejor << endl;

    return 0;
}
