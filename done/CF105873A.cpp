#include <bits/stdc++.h>

using namespace std;

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
    int m = p.size() / s.size();
    string att = "";
    while (m--) {
      att += s;
    }
    if (att == p) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
