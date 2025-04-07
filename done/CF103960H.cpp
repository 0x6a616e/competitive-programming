#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<bool> visited;
int curr_time;
vector<pair<int, int>> times;
vector<int> component;
int curr_comp = 0;
vector<set<int>> component_adj;
vector<pair<int, int>> edges;

void dfs1(int node) {
  if (visited[node]) {
    return;
  }
  ++curr_time;
  visited[node] = true;
  for (int child : adj[node]) {
    dfs1(child);
  }
  ++curr_time;
  times.push_back({node, curr_time});
}

void dfs2(int node) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  component[node] = curr_comp;
  for (int child : rev_adj[node]) {
    dfs2(child);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  rev_adj.resize(n + 1);
  visited.resize(n + 1, false);
  component.resize(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    rev_adj[b].push_back(a);
    edges.push_back({a, b});
  }

  curr_time = 0;
  for (int i = 1; i <= n; ++i) {
    dfs1(i);
  }

  reverse(times.begin(), times.end());
  visited.assign(n + 1, false);
  for (pair<int, int> time : times) {
    if (component[time.first] == 0) {
      ++curr_comp;
      dfs2(time.first);
    }
  }

  component_adj.resize(curr_comp + 1);
  visited.assign(n + 1, false);
  for (pair<int, int> edge : edges) {
    int c1 = component[edge.first];
    int c2 = component[edge.second];
    if (c1 != c2) {
      component_adj[c1].insert(c2);
      visited[c2] = true;
    }
  }

  int sources = 0;
  int sinks = 0;
  for (int i = 1; i <= curr_comp; ++i) {
    if (!visited[i]) {
      ++sources;
    }
    if (component_adj[i].size() == 0) {
      ++sinks;
    }
  }
  if (curr_comp == 1) {
    cout << "0\n";
  } else {
    cout << max(sources, sinks) << '\n';
  }

  return 0;
}
