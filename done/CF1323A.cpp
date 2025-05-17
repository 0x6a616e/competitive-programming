#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int fo = 0;
    int so = 0;
    int fe = 0;

    for (int i = 0; i < n; ++i) {
      int ai;
      cin >> ai;
      if (ai % 2 == 0) {
        if (fe == 0) {
          fe = i + 1;
        }
      } else {
        if (fo == 0) {
          fo = i + 1;
        } else if (so == 0) {
          so = i + 1;
        }
      }
    }
    if (fe != 0) {
      cout << "1\n";
      cout << fe << '\n';
    } else if (fo != 0 && so != 0) {
      cout << "2\n";
      cout << fo << ' ' << so << '\n';
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
