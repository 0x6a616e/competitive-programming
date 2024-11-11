#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin >> s;

  set<char> dups;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (dups.count(s[i])) {
      cout << i + 1 << endl;
      break;
    }
    dups.insert(s[i]);
  }

  return 0;
}
