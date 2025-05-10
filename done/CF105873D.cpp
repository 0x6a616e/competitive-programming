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
  vector<long long> day_usage(k, 0);
  vector<vector<long long>> orders(n, vector<long long>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> orders[i][j];
      day_usage[j] += orders[i][j];
    }
  }

  long long days = 1e12;
  for (int i = 0; i < k; ++i) {
    if (day_usage[i] == 0) {
      continue;
    }
    days = min(days, inventory[i] / day_usage[i]);
  }
  for (int i = 0; i < k; ++i) {
    inventory[i] -= day_usage[i] * days;
  }

  int order_count = -1;
  for (int i = 0; i < n && order_count == -1; ++i) {
    for (int j = 0; j < k && order_count == -1; ++j) {
      if (inventory[j] < orders[i][j]) {
        order_count = i + 1;
      }
      inventory[j] -= orders[i][j];
    }
  }

  cout << ++days << ' ' << order_count << '\n';

  return 0;
}
