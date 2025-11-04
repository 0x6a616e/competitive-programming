#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> best(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int g;
            cin >> g;
            best[j] = max(best[j], g);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) ans += best[i];
    cout << ans << endl;

    return 0;
}
