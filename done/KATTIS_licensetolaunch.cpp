#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    
    int best = 0;
    int best_i = -1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (best_i == -1 || x < best) {
            best = x;
            best_i = i;
        }
    }

    cout << best_i << '\n';

    return 0;
}
