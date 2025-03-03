#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long rangeSum(vector<long long> &input, int l, int r) {
  long long res = input[r] - input[l - 1];
  if (res <= 0) {
    res += MOD;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<long long> sums1(n + 1, 0);
  vector<long long> sums2(n + 1, 0);
  {
    long long ai;
    for (int i = 1; i <= n; ++i) {
      cin >> ai;
      sums1[i] = (sums1[i - 1] + ai) % MOD;
      sums2[i] = (ai * ai) % MOD;
      sums2[i] = (sums2[i - 1] + sums2[i]) % MOD;
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    long long ans = rangeSum(sums1, l, r);
    long long squares = rangeSum(sums2, l, r);
    if (l != r) {
      ans = (((ans % MOD) * (ans % MOD) % MOD) - (squares % MOD)) % MOD;
      if (ans <= 0) {
        ans += MOD;
      }
      ans *= 500000004;
    }
    cout << ans % MOD << '\n';
  }

  return 0;
}
