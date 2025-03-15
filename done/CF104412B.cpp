#include <bits/stdc++.h>

using namespace std;

void debug_print(int i) { cout << "DEBUG: " << i << endl; }

const int MOD = 1e9 + 7;

int modpow(int x, int n, int m) {
  if (n == 0) {
    return 1 % m;
  }
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) {
    u = (u * x) % m;
  }
  return u;
}

int divide(long long numerator, long long divisor, int m) {
  long long ans = 0;
  divisor = modpow(divisor, m - 2, m);
  ans = (numerator * divisor) % m;
  return ans;
}

int factorial(int n, int m) {
  long long u = 1LL;
  for (int i = 2; i <= n; ++i) {
    u = (u * i) % m;
  }
  return u % m;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  long long numerator = factorial(n, MOD);
  long long divisor = 1;
  map<int, int> frequencies;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    divisor = (divisor * ++frequencies[nums[i]]) % MOD;
  }
  cout << modpow(divide(numerator, divisor, MOD), MOD - 2, MOD) << '\n';

  while (k--) {
    int a, b;
    cin >> a >> b;
    --a;
    divisor = divide(divisor, frequencies[nums[a]]--, MOD);
    nums[a] = b;
    divisor = (divisor * ++frequencies[nums[a]]) % MOD;
    cout << modpow(divide(numerator, divisor, MOD), MOD - 2, MOD) << '\n';
  }

  return 0;
}
