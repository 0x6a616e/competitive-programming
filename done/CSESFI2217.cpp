// https://cses.fi/problemset/task/2217

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    unordered_map<int, int> posiciones;
    unordered_map<int, bool> padres;

    int n, m;
    cin >> n >> m;

    int nums[n + 1];
    int sol = n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        posiciones[nums[i]] = i;
        if (posiciones[nums[i] - 1]) {
            --sol;
            padres[nums[i]] = true;
        } else {
            padres[nums[i]] = false;
        }
    }

    int l, r;
    while (m--) {
        cin >> l >> r;
        int a = nums[l];
        int b = nums[r];
        swap(nums[l], nums[r]);
        swap(posiciones[a], posiciones[b]);
        if (a != 1 && a <= n && padres[a] && posiciones[a] < posiciones[a - 1]) {
            padres[a] = false;
            ++sol;
        }
        if (a != 1 && a <= n && !padres[a] && posiciones[a] > posiciones[a - 1]) {
            padres[a] = true;
            --sol;
        }
        ++a;
        if (a != 1 && a <= n && padres[a] && posiciones[a] < posiciones[a - 1]) {
            padres[a] = false;
            ++sol;
        }
        if (a != 1 && a <= n && !padres[a] && posiciones[a] > posiciones[a - 1]) {
            padres[a] = true;
            --sol;
        }

        if (b != 1 && b <= n && padres[b] && posiciones[b] < posiciones[b - 1]) {
            padres[b] = false;
            ++sol;
        }
        if (b != 1 && b <= n && !padres[b] && posiciones[b] > posiciones[b - 1]) {
            padres[b] = true;
            --sol;
        }
        ++b;
        if (b != 1 && b <= n && padres[b] && posiciones[b] < posiciones[b - 1]) {
            padres[b] = false;
            ++sol;
        }
        if (b != 1 && b <= n && !padres[b] && posiciones[b] > posiciones[b - 1]) {
            padres[b] = true;
            --sol;
        }

        cout << sol << '\n';
    }

    return 0;
}
