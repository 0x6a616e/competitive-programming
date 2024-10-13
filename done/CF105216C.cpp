#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q;
  cin >> q;
  while (q--) {
    int n, t;
    cin >> n >> t;
    if (t == 1) {
      cout << n << '\n';
      continue;
    }
    int sol = 0;
    --t;
    for (int i = 1; (ll)i * i <= t; ++i) {
      if (t % i == 0) {
        if (i <= n) ++sol;
        if (t / i <= n) ++sol;
        if (i * i == t) --sol;
      }
    }
    cout << sol << '\n';
  }

  return 0;
}
