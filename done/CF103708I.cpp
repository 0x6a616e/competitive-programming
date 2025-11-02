// https://codeforces.com/gym/103708/problem/I

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int ans = 0;
    int aux = n;
    while (aux) {
        int att = aux % 10;
        if (att && n % att == 0) {
            ++ans;
        }
        aux /= 10;
    }
    cout << ans << endl;

    return 0;
}
