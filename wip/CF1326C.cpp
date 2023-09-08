#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, n;
    cin >> n >> k;
    int p[n];
    bool l[n];
    vector<int> limites;
    int modulo = 998244353;
    unsigned long long acum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > n - k) l[i] = true;
        if (p[i] <= n - k) l[i] = false;
        if (l[i]) limites.push_back(i);
        if (l[i]) acum += p[i];
    }

    vector<int> acums(limites.size());

    unsigned long long sol = 1;

    for (int i = 0; i < (int)limites.size() - 1; ++i) {
        int curr = limites[i + 1] - limites[i] - 1;

        if (i) curr = curr + curr * acums[i - 1];

        sol += curr;
        acums[i] = curr;
    }

    cout << acum << " " << sol % modulo << endl;

    return 0;
}
