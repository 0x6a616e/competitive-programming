#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct matrix {
  long long mat[2][2];
  matrix friend operator*(const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c.mat[i][j] = 0;
        for (int k = 0; k < 2; k++) {
          c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j] % MOD) % MOD;
        }
      }
    }
    return c;
  }
};

matrix matpow(matrix ans, matrix base, int n) {
  while (n) {
    if (n & 1)
      ans = ans * base;
    base = base * base;
    n >>= 1;
  }
  return ans;
}

long long fib(long long b, int n) {
  matrix base{{{1, 1}, {1, 0}}};
  matrix ans{{{b, 0}, {0, b}}};
  return matpow(ans, base, n).mat[0][1];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> mi(m);
  for (int i = 0; i < m; ++i) {
    cin >> mi[i];
  }
  sort(mi.begin(), mi.end());
  int b = 1;
  int prev = -1;
  bool cut = false;
  for (int i = 0; i < m; ++i) {
    if (mi[i] - prev == 1) {
      cut = true;
      break;
    }
    if (mi[i] - prev > 3) {
      b = fib(b, mi[i] - prev - 1);
    }
    prev = mi[i];
  }
  if (cut) {
    cout << "0\n";
  } else {
    b = fib(b, n - prev);
    cout << b << '\n';
  }

  return 0;
}
