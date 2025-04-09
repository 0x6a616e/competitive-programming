#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int last_idx;
    for (int i = (int)n.size() - 1; i >= 0; --i) {
      if (n[i] - '0' > 0) {
        last_idx = i;
        break;
      }
    }
    int ans = (int)n.size() - last_idx - 1;
    for (int i = 0; i < last_idx; ++i) {
      if (n[i] - '0' > 0) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
