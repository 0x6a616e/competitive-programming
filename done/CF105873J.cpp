#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  string s;
  cin >> n >> s;

  bitset<26> freqs;
  vector<int> indexes(1 << 26, -1);
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    freqs.flip(s[i] - 'a');

    if (((i + 1) % 2 == 0 && freqs.count() == 0) ||
        ((i + 1) % 2 != 0 && freqs.count() == 1)) {
      ans = max(ans, i + 1);
    }

    if (indexes[freqs.to_ulong()] != -1) {
      ans = max(ans, i - indexes[freqs.to_ulong()]);
    } else {
      indexes[freqs.to_ulong()] = i;
    }

    for (int j = 0; j < 26; ++j) {
      freqs.flip(j);
      if (indexes[freqs.to_ulong()] != -1) {
        int d = i - indexes[freqs.to_ulong()];
        if (d % 2 != 0) {
          ans = max(ans, d);
        }
      }
      freqs.flip(j);
    }
  }

  cout << ans << '\n';

  return 0;
}
