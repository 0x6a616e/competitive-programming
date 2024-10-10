#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin >> s >> s;

  set<int> valid = {1, 2, 3, 4, 5, 7, 9};
  int sol = 0;
  for (char c : s) {
    if (valid.count(c - '0')) {
      ++sol;
    }
  }

  cout << sol << '\n';

  return 0;
}
