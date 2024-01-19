// https://codeforces.com/problemset/problem/725/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    char s;

    cin >> n >> s;

    long long base = (n - 1) / 4;
    long long sol = base * 16;
    long long b = 4 * base + 1;

    if (n != b && n != b + 2) sol += 7;

    for (char c : {'f', 'e', 'd', 'a', 'b', 'c'}) {
        ++sol;
        if (s == c) break;
    }

    cout << sol << endl;

    return 0;
}
