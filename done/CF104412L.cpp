#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> X(n);
  int S = 0;
  for (int &xi : X) {
    cin >> xi;
    S += xi;
  }

  vector<vector<bool>> dp(S + 1, vector<bool>(S + 1, false));
  dp[0][0] = true;

  for (int xi : X) {
    for (int x = S; x >= 0; --x) {
      for (int y = S; y >= 0; --y) {
        if (dp[x][y]) {
          dp[x + xi][y] = true;
          dp[x][y + xi] = true;
        }
      }
    }
  }

  int ans = 1e9;
  for (int x = 0; x <= S; ++x) {
    for (int y = 0; y <= S; ++y) {
      if (dp[x][y]) {
        double t1 = (double)x / a;
        double t2 = (double)y / b;
        double t3 = (double)(S - x - y) / c;
        double max_t = max({t1, t2, t3});
        ans = min(ans, (int)ceil(max_t));
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
