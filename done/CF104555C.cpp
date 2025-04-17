#include <bits/stdc++.h>

using namespace std;

void topo_dfs(vector<vector<int>> &adj, vector<int> &values, vector<int> &ans,
              vector<int> lis, int p, int c) {
  if (lis.empty() || values[c] > lis.back()) {
    lis.push_back(values[c]);
  } else {
    auto lb = lower_bound(lis.begin(), lis.end(), values[c]);
    *lb = values[c];
  }
  ans[c] = lis.size();
  for (int child : adj[c]) {
    if (child != p) {
      topo_dfs(adj, values, ans, lis, c, child);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 2; i < n + 1; ++i) {
    int pi;
    cin >> pi;
    adj[i].push_back(pi);
    adj[pi].push_back(i);
  }

  vector<int> v(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> v[i + 1];
  }

  vector<int> ans(n + 1, 0);
  vector<int> lis;
  topo_dfs(adj, v, ans, lis, 0, 1);
  for (int i = 2; i <= n; ++i) {
    cout << (i == 2 ? "" : " ") << ans[i];
  }

  return 0;
}
