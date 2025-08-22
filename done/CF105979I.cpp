#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;

  while (q--) {
    long long x, x2, k;
    cin >> x >> k;
    x2 = x;
    int i = 1;
    while (x < k) {
      ++i;
      x += x2;
      x2 = x - x2;
    }
    cout << i << '\n';
  }

  return 0;
}
