#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pllll;
typedef vector<pllll> vpllll;

#define F first
#define S second

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vi distances(n - 1);
  for (int i = 0; i < n - 1; ++i) cin >> distances[i];

  vi wait(n);
  for (int i = 0; i < n; ++i) cin >> wait[i];

  vpllll train1;
  ll t = 1;
  for (int i = 0; i < n; ++i) {
    train1.push_back({t, t + wait[i]});
    t += wait[i];
    if (i < n - 1) t += distances[i];
  }

  vpllll train2;
  t = 1;
  for (int i = n - 1; i >= 0; --i) {
    train2.push_back({t, t + wait[i]});
    t += wait[i];
    if (i > 0) t += distances[i - 1];
  }
  reverse(train2.begin(), train2.end());

  ll sol = 0;
  for (int i = 0; i < n; ++i) {
    pllll t1 = train1[i];
    pllll t2 = train2[i];
    if (t2.F > t1.S || t2.S < t1.F) continue;
    ll e = max(t1.F, t2.F);
    ll s = min(t1.S, t2.S);
    sol += (s - e);
  }

  cout << sol << '\n';

  return 0;
}
