#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> l(n);
  for (int &li : l) {
    cin >> li;
  }
  vector<int> r(n);
  for (int &ri : r) {
    cin >> ri;
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  int ans = 0;
  int idx = 0;
  while (idx < n) {
    int c = l[idx] + r[idx];
    if (c <= k) {
      ++ans;
      ++idx;
      k -= c;
    } else {
      break;
    }
  }
  cout << ans << '\n';

  return 0;
}
