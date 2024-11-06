#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<int> z(vector<int> s) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i - x], y - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      x = i;
      y = i + z[i];
      ++z[i];
    }
  }
  return z;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m, n;
  cin >> m >> n;
  vector<int> s;
  {
    vector<int> mi(m);
    for (int i = 0; i < m; ++i) cin >> mi[i];
    for (int i = 1; i < m; ++i) s.push_back(mi[i] - mi[i - 1]);
    s.push_back(INF * 2);
  }
  {
    vector<int> ni(n);
    for (int i = 0; i < n; ++i) cin >> ni[i];
    for (int i = 1; i < n; ++i) s.push_back(ni[i] - ni[i - 1]);
  }

  vector<int> z_arr = z(s);
  int sol = 0;
  for (int zi : z_arr)
    if (zi == m - 1) ++sol;

  cout << sol << '\n';

  return 0;
}
