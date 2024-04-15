// https://cses.fi/problemset/task/2217

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    map<int, int> posiciones;
    map<int, bool> padres;

    int n, m;
    cin >> n >> m;

    int nums[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        posiciones[nums[i]] = i;
        if (posiciones[nums[i] - 1])
            padres[nums[i]] = true;
        else
            padres[nums[i]] = false;
    }

    int sol = 0;

    int a, b;
    // while (m--) {
    //     cin >> a >> b;
    // }

    return 0;
}
