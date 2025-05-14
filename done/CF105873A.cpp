#include <bits/stdc++.h>

using namespace std;

string solve(string &s, string &p) {
  if (p.size() % s.size() != 0) {
    return "No";
  }
  for (int i = 0; i < (int)p.size(); ++i) {
    if (p[i] != s[i % s.size()]) {
      return "No";
    }
  }
  return "Yes";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string p;
    cin >> p;
    cout << solve(s, p) << '\n';
  }

  return 0;
}
