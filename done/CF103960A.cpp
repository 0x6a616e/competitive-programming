// https://codeforces.com/gym/103960/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int cg = 0;
    int cl = 0;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == 'a')
            ++cl;
        else {
            cg += (cl == 1 ? 0 : cl);
            cl = 0;
        }
    }
    cg += (cl == 1 ? 0 : cl);
    cout << cg << '\n';
    return 0;
}
