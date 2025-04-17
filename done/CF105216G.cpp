#include <bits/stdc++.h>

using namespace std;

void children_dfs(vector<vector<int>> &adj, vector<int> &children, int node) {
  if (children[node] != -1) {
    return;
  }
  children[node] = 0;
  for (int child : adj[node]) {
    children_dfs(adj, children, child);
    children[node] += children[child] + 1;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << ':';
  //   for (int child : adj[i]) {
  //     cout << ' ' << child;
  //   }
  //   cout << endl;
  // }

  vector<int> children(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    children_dfs(adj, children, i);
  }
  // for (int i = 1; i <= n; ++i) {
  //     cout << i << ": " << children[i] << endl;
  // }

  vector<long long> usage(n + 1);
  long long max_usage = 0;
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    usage[i] = 1LL * (n - children[i] - 1) * (children[i] + 1);
    if (usage[i] > max_usage) {
      max_usage = usage[i];
      count = 1;
    } else if (usage[i] == max_usage) {
      ++count;
    }
  }

  cout << max_usage << ' ' << count << '\n';

  return 0;
}
