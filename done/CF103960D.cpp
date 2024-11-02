#include <bits/stdc++.h>

using namespace std;

typedef long long C;
typedef pair<C, C> P;
#define X first
#define Y second

P solve(P &base, P &res) {
  int x = res.X * 2 - base.X;
  int y = res.Y * 2 - base.Y;
  P sol{x, y};
  return sol;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, x, y;
  cin >> n >> x >> y;

  vector<P> attrs = {P{0, 0}, P{0, 1 << n}, P{1 << n, 0}, P{1 << n, 1 << n}};
  P target{1 << (n - 1), 1 << (n - 1)};
  P source{x, y};
  P sep{-1, -1};
  int sol = 0;
  queue<P> pendientes;
  pendientes.push(source);
  pendientes.push(sep);
  while (!pendientes.empty()) {
    P curr = pendientes.front();
    pendientes.pop();
    if (curr == sep) {
      ++sol;
      pendientes.push(sep);
      continue;
    }
    if (curr == target) break;
    for (P attr : attrs) {
      P attempt = solve(attr, curr);
      if (attempt >= attrs[0] && attempt <= attrs[3]) pendientes.push(attempt);
    }
  }

  cout << sol << '\n';

  return 0;
}
