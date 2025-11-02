// https://codeforces.com/gym/104375/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k, l;
    cin >> n >> k >> l;
    cout << (n * k + l - 1) / l << endl;

    return 0;
}
