#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int A, B, C, a, b, c;
  cin >> A >> B >> C;
  cin >> a >> b >> c;

  int sol = 0;
  sol = max(sol, (A / a) * (B / b) * (C / c));
  sol = max(sol, (A / a) * (B / c) * (C / b));
  sol = max(sol, (A / b) * (B / a) * (C / c));
  sol = max(sol, (A / b) * (B / c) * (C / a));
  sol = max(sol, (A / c) * (B / a) * (C / b));
  sol = max(sol, (A / c) * (B / b) * (C / a));

  cout << sol << '\n';

  return 0;
}
