#include <bits/stdc++.h>

using namespace std;

char sw(char a) { return (a == '0' ? '1' : '0'); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k;
  string s;
  cin >> k >> s;

  vector<pair<int, int>> limits;
  for (int i = 0; i < (int)s.size(); ++i) {
    int e = i;
    while (e < (int)s.size() && s[i] == s[e]) ++e;
    limits.push_back({i, e - 1});
    i = e - 1;
  }

  int sol = 0;
  for (int i = 0; i < (int)limits.size(); ++i) {
    pair<int, int> group = limits[i];
    int len = group.second - group.first + 1;
    if (len < k) continue;
    if (k == 2) {
      if (len % k == 0) {
        int next_len = 2;
        if (i + 1 < (int)limits.size()) {
          pair<int, int> next_group = limits[i + 1];
          next_len = next_group.second - next_group.first + 1;
        }
        int init;
        if (i == 0 && next_len % 2 != 0) {
          init = group.first;
        } else {
          init = group.first + 1;
          if (i + 1 < (int)limits.size()) {
            --limits[i + 1].first;
          }
        }
        for (int j = init; j <= group.second; j += 2) {
          s[j] = sw(s[j]);
          ++sol;
        }
      } else {
        for (int j = group.first + 1; j <= group.second; j += 2) {
          s[j] = sw(s[j]);
          ++sol;
        }
      }
    } else {
      int init;
      if (len % k == 0) {
        init = group.first + 1;
      } else {
        init = group.first + k - 1;
      }
      for (int j = init; j <= group.second; j += k) {
        s[j] = sw(s[j]);
        ++sol;
      }
    }
  }

  cout << sol << ' ' << s << endl;

  return 0;
}
