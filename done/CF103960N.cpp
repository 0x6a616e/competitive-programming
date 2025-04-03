#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int k, l;
  cin >> k >> l;

  ll curr_front = 0;
  ll curr_back = 0;
  indexed_set backs;
  for (int i = 0; i < k; ++i) {
    curr_front += a[i];
    backs.insert({b[i], i});
  }
  for (int i = k - l; i < k; ++i) {
    curr_back += backs.find_by_order(i)->first;
  }
  ll ans = curr_front + curr_back;
  int left = k - 1;
  int right = n - 1;
  while (left >= 0) {
    curr_front -= a[left];
    curr_front += a[right];

    bool changed = false;
    if ((int)backs.order_of_key({b[left], left}) >= k - l) {
      changed = true;
      curr_back -= b[left];
    }
    backs.erase({b[left], left});

    backs.insert({b[right], right});
    if ((int)backs.order_of_key({b[right], right}) >= k - l) {
      curr_back += b[right];
      if (!changed) {
        curr_back -= backs.find_by_order(k - l - 1)->first;
      }
    } else if (changed) {
      curr_back += backs.find_by_order(k - l)->first;
    }

    ans = max(ans, curr_front + curr_back);
    --left;
    --right;
  }

  cout << ans << '\n';

  return 0;
}
