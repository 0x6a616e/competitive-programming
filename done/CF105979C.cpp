#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  long long ans = 1;
  vector<long long> memo(1e5 + 1, 0);
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    if (memo[ai]) {
      ans += memo[ai];
      if (ans >= MOD) {
        ans %= MOD;
      }
    }
    memo[ai] = ans;
  }
  cout << ans << '\n';

  return 0;
}
