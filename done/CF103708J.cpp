#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;

int n, m;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (int to : g[v]) {
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> m;
  g.assign(n, vector<int>());
  for (int p = 0; p < n; ++p) {
    int k;
    cin >> k;
    g[p].assign(k, 0);
    for (int i = 0; i < k; ++i) {
      cin >> g[p][i];
      --g[p][i];
    }
  }

  mt.assign(m, -1);
  vector<bool> used1(n, false);
  for (int v = 0; v < n; ++v) {
    for (int to : g[v]) {
      if (mt[to] == -1) {
        mt[to] = v;
        used1[v] = true;
        break;
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    if (used1[v]) continue;
    used.assign(n, false);
    try_kuhn(v);
  }

  int flow = m;
  for (int i = 0; i < m; ++i)
    if (mt[i] != -1) --flow;

  cout << flow << '\n';

  return 0;
}
