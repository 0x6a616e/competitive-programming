#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;

void DEBUG(vvll &a) {
  cout << "---\n";
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)a[i].size(); ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "---\n";
}

vvll multiply(vvll &a, vvll &b) {
  int n = (int)a.size();
  vvll ans(n, vll(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ans[i][j] += a[i][k] * b[k][j];
        ans[i][j] %= MOD;
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  vvll adj(n, vll(n, 0));
  vvll ans(n, vll(n, 0));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  for (int i = 0; i < n; ++i) ans[i][i] = 1;

  while (k) {
    if (k & 1) {
      ans = multiply(ans, adj);
    }
    adj = multiply(adj, adj);
    k >>= 1;
  }

  ll sol = 0;
  for (int i = 0; i < n; ++i) {
    sol += ans[0][i];
    sol %= MOD;
  }

  cout << sol << '\n';

  return 0;
}
