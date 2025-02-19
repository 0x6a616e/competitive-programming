#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  int prev = -1;
  int curr;
  int sol = 1;
  while (n--) {
    cin >> curr;
    if (prev % 10 == curr / 10)
      ++sol;
    prev = curr;
  }

  cout << sol << '\n';

  return 0;
}
