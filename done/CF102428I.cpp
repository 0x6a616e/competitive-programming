#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long memo[2001];
int hit[2001];

long long solve(vector<vector<int>> &adj, int i) {
  hit[i] = 1;
  if (memo[i] == -1) {
    memo[i] = 0;
    for (int ai : adj[i]) {
      memo[i] = (memo[i] + solve(adj, ai)) % MOD;
    }
  }
  return memo[i];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, l;
  cin >> n >> l;

  for (int i = 1; i <= n; ++i) {
    hit[i] = 0;
    if (i <= l) {
      memo[i] = -1;
    } else {
      memo[i] = 1;
    }
  }

  vector<vector<int>> adj(l + 1);
  for (int i = 1; i <= l; ++i) {
    int k;
    cin >> k;
    adj[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> adj[i][j];
    }
  }

  long long b = solve(adj, 1);
  long long a = 0;
  for (int i = l + 1; i <= n; ++i) {
    a += hit[i];
  }
  cout << b << ' ' << a << '\n';

  return 0;
}
