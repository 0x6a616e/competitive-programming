#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        int n_tracks;
        cin >> n_tracks;
        int tracks[n_tracks];
        for (int i = 0; i < n_tracks; ++i) cin >> tracks[i];
        pair<int, int> mejor = {0, 0};
        for (int i = 0; i < (1 << n_tracks); ++i) {
            int total = 0;
            for (int j = 0; j < n_tracks && total <= n; ++j)
                if (i & (1 << j)) total += tracks[j];

            if (total > n) continue;
            if (total > mejor.second) mejor = {i, total};
        }
        for (int i = 0; i < 20; ++i)
            if (mejor.first & (1 << i)) cout << tracks[i] << ' ';
        cout << "sum:" << mejor.second << '\n';
    }

    return 0;
}
