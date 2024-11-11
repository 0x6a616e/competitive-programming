#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k, n;
  cin >> k >> n;

  int low = ceil(n, 3);
  int up = ceil(n, 2);

  if (k >= low && k <= up) {
    string sol = "";
    int curr = 0;
    int remaining = n;
    while (curr + ceil(remaining, 2) > k) {
      sol += "-X-";
      ++curr;
      remaining -= 3;
    }
    while ((int)sol.size() < n) {
      sol += "X-";
    }
    while ((int)sol.size() > n) {
      sol.pop_back();
    }
    cout << sol;
  } else {
    cout << '*';
  }
  cout << endl;

  return 0;
}
