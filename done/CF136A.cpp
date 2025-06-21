#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int pi;
    cin >> pi;
    ans[pi - 1] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << ans[i];
  }

  return 0;
}
