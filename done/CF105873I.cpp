#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<unordered_map<int, int>> &knowers,
         vector<bool> &visited, int node) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  for (int child : adj[node]) {
    dfs(adj, knowers, visited, child);
    for (pair<int, int> freqs : knowers[child]) {
      knowers[node][freqs.first] += freqs.second;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<unordered_map<int, int>> knowers(n + 1);
  for (int i = 1; i <= n; ++i) {
    int ki;
    cin >> ki;
    ++knowers[i][ki];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }

  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    dfs(adj, knowers, visited, i);
  }

  for (int i = 0; i < q; ++i) {
    int x, k;
    cin >> x >> k;
    cout << knowers[x][k] << '\n';
  }

  return 0;
}
