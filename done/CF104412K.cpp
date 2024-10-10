#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; ++i)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  int grid[n][n];
  REP(i, 0, n) {
    REP(j, 0, n) { cin >> grid[i][j]; }
  }

  int sol = 0;
  --k;
  REP(i, 0, n) {
    if (i + k >= n) continue;
    REP(j, 0, n) {
      if (j + k >= n) continue;
      if (grid[i][j] == grid[i][j + k] && grid[i][j] == grid[i + k][j] &&
          grid[i][j] == grid[i + k][j + k]) {
        ++sol;
      }
    }
  }

  cout << sol << '\n';

  return 0;
}
