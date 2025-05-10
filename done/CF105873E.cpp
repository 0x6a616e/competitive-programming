#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int sol = -1;
  for (int i = 0; i < n && sol == -1; ++i) {
    int a;
    cin >> a;
    if (a >= m) {
      sol = i + 1;
    }
  }
  cout << sol << endl;

  return 0;
}
