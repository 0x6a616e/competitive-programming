#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subs;
vector<int> groups;
vector<int> counts;
vector<int> curr;
int curr_c;

void solve(int person) {
  if (++curr[groups[person]] == 1) {
    ++curr_c;
  }
  counts[person] = curr_c;
  for (int sub : subs[person]) {
    solve(sub);
  }
  if (--curr[groups[person]] == 0) {
    --curr_c;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  subs.resize(n + 1);
  groups.resize(n + 1);
  counts.resize(n + 1);

  int si;
  for (int i = 1; i <= n; ++i) {
    cin >> si;
    subs[si].push_back(i);
  }

  int gi;
  for (int i = 1; i <= n; ++i) {
    cin >> gi;
    groups[i] = gi;
  }

  curr.resize(n + 1, 0);
  curr_c = 0;
  solve(subs[0][0]);

  for (int i = 1; i <= n; ++i) {
    cout << (i > 1 ? " " : "") << counts[i];
  }

  return 0;
}
