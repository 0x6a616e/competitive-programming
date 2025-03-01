#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> activities;
  for (int i = 0; i < n; ++i) {
    int s, d;
    cin >> s >> d;
    activities.push_back({s, d});
  }

  pair<int, int> best = {1000000000, 0};
  for (int i = 0; i <= 480; ++i) {
    pair<int, int> curr = {0, i};
    for (pair<int, int> activity : activities) {
      if (curr.first > best.first) {
        break;
      }
      int first_take = i;
      if (i < activity.first) {
        int d = activity.first - i;
        int c = ceil(d, x);
        first_take += c * x;
      }
      int diff = first_take - activity.first;
      if (diff > activity.second) {
        continue;
      }
      int duration = activity.second - diff;
      curr.first += 1 + duration / x;
    }
    best = min(best, curr);
  }

  cout << best.second << ' ' << best.first << '\n';

  return 0;
}
