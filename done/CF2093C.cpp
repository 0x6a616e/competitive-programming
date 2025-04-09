#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  for (long long x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    int n = 1;
    if (x == 1 && k != 1) {
      for (int i = 1; i < k; ++i) {
        n *= 10;
        ++n;
      }
    }
    if (k == 1 && x != 1 && is_prime(x)) {
      cout << "YES\n";
    } else if (x == 1 && k != 1 && is_prime(n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
