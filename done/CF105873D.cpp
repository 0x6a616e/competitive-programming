#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int k;
  cin >> k;

  vector<long long> inventory(k);
  for (long long &a : inventory) {
    cin >> a;
  }

  int n;
  cin >> n;
  vector<vector<long long>> orders(n, vector<long long>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> orders[i][j];
      if (i > 0) {
        orders[i][j] += orders[i - 1][j];
      }
    }
  }

  long long days = 1e12;
  for (int i = 0; i < k; ++i) {
    if (orders[n - 1][i] == 0) {
      continue;
    }
    days = min(days, inventory[i] / orders[n - 1][i]);
  }
  for (int i = 0; i < k; ++i) {
    inventory[i] -= orders[n - 1][i] * days;
  }

  int order_count = -1, l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    bool day_over = false;
    for (int i = 0; i < k && !day_over; ++i) {
      if (inventory[i] < orders[m][i]) {
        day_over = true;
      }
    }
    if (day_over) {
      order_count = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << ++days << ' ' << ++order_count << '\n';

  return 0;
}
