#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> order(n);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        order[x] = i;
    }

    cout << "1";
    for (int i = 0; i < n - 1; ++i) {
        cout << ' ' << order[i];
    }
    cout << '\n';

    return 0;
}
