#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  vector<int> curr = {3, 2};
  int curr_n = 5;
  while (curr_n < n) {
    for (int i = 0; i < curr.size() && curr_n != n; ++i) {
      ++curr[i];
      ++curr_n;
    }
    if (curr_n == n) {
      break;
    }
    ++curr_n;
    ++curr[0];
    if (curr_n == n) {
      break;
    }
    ++curr_n;
    --curr[0];
    curr.push_back(2);
  }
  return curr;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    vector<int> s = solve(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
      cout << (i == 0 ? "" : " ") << s[i];
    }
    cout << '\n';
    if (m) {
      cout << '\n';
    }
  }

  return 0;
}
