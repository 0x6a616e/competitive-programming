#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, ll> f(ll x, ll y, ll c, int n, ll t) {
  if (n == 0) {
    return {x, y};
  }
  ll step = (1LL << (2 * n - 2));
  if (t <= c + step - 1) {
    return f(x, y, c, n - 1, t);
  } else if (t <= c + 2 * step - 1) {
    return f(x + (1LL << (n - 1)), y + (1LL << (n - 1)), c + step, n - 1, t);
  } else if (t <= c + 3 * step - 1) {
    return f(x + (1LL << (n - 1)), y, c + 2 * step, n - 1, t);
  } else if (t <= c + 4 * step - 1) {
    return f(x, y + (1LL << (n - 1)), c + 3 * step, n - 1, t);
  }
}

ll f(ll x, ll y, ll c, int n, ll tx, ll ty) {
  if (n == 0) {
    return c;
  }
  ll step = (1LL << (2 * n - 2));
  if (tx <= x + (1LL << (n - 1)) - 1 && ty <= y + (1LL << (n - 1)) - 1) {
    return f(x, y, c, n - 1, tx, ty);
  } else if (tx > x + (1LL << (n - 1)) - 1 && ty > y + (1LL << (n - 1)) - 1) {
    return f(x + (1LL << (n - 1)), y + (1LL << (n - 1)), c + step, n - 1, tx,
             ty);
  } else if (tx > x + (1LL << (n - 1)) - 1 && ty <= y + (1LL << (n - 1)) - 1) {
    return f(x + (1LL << (n - 1)), y, c + 2 * step, n - 1, tx, ty);
  } else if (tx <= x + (1LL << (n - 1)) - 1 && ty > y + (1LL << (n - 1)) - 1) {
    return f(x, y + (1LL << (n - 1)), c + 3 * step, n - 1, tx, ty);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    while (q--) {
      string op;
      cin >> op;
      if (op == "->") {
        ll x, y;
        cin >> x >> y;
        ll res = f(1, 1, 1, n, x, y);
        cout << res << '\n';
      } else if (op == "<-") {
        ll d;
        cin >> d;
        pair<ll, ll> pos = f(1, 1, 1, n, d);
        cout << pos.first << ' ' << pos.second << '\n';
      }
    }
  }

  return 0;
}
