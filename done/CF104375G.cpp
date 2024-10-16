#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi memo;

int solve(int rem, int turn) {
  if (rem <= turn) return 1;
  if (memo[rem][turn] == -1) {
    int sol = 0;
    for (int i = turn; i > 0 && sol == 0; --i) {
      int si = solve(rem - i, turn + 1);
      if (si == 0) sol = 1;
    }
    memo[rem][turn] = sol;
  }
  return memo[rem][turn];
}

int main() {
  int n;
  cin >> n;

  memo.assign(n + 1, vi(n + 1, -1));

  if (solve(n, 1) == 1)
    cout << "Jane\n";
  else
    cout << "John\n";
}
