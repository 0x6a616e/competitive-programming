#include <bits/stdc++.h>

using namespace std;

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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<long long> fs(m + 1);
  fs[0] = fs[1] = 1;
  for (int i = 2; i <= m; ++i) {
    fs[i] = fs[i - 1] * i % MOD;
  }
  vector<long long> ifs(m + 1);
  for (int i = 0; i <= m; ++i) {
    ifs[i] = modpow(fs[i], MOD - 2, MOD);
  }

  long long bc = fs[m] * ifs[k] % MOD * ifs[m - k] % MOD;

  long long s = 0;
  for (int i = 0; i <= k; ++i) {
    long long numerator = modpow(-1, k - i, MOD) * modpow(i, n, MOD);
    long long denominator = ifs[k - i] * ifs[i] % MOD;
    s = (s + numerator * denominator % MOD) % MOD;
  }

  long long ans = fs[k] * bc % MOD * s % MOD;
  if (ans < 0) {
    ans += MOD;
  }
  cout << ans << '\n';

  return 0;
}
