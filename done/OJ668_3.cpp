#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    int rem = n;

    set<int> sol;
    for (int i = 1; i <= rem; ++i) {
      sol.insert(i);
      rem -= i;
    }
    if (rem) {
      for (int i : sol) {
        if (!sol.count(i + rem)) {
          sol.erase(i);
          sol.insert(i + rem);
          break;
        }
      }
    }
    if (sol.count(1)) {
      sol.erase(1);
      for (int i : sol) {
        if (!sol.count(i + 1)) {
          sol.erase(i);
          sol.insert(i + 1);
          break;
        }
      }
    }

    string sep = "";
    for (int i : sol) {
      cout << sep << i;
      sep = " ";
    }
    cout << '\n';
    if (m) {
      cout << '\n';
    }
  }

  return 0;
}
