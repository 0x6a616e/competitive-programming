#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  int total = 0;
  vector<int> clock(n);
  vector<int> counter_clock(n);
  for (int i = 0; i < n; ++i) {
    int gi;
    cin >> gi;
    clock[i] = gi;
    counter_clock[i] = gi;
    total += gi;
  }
  long long target = total / n;

  long long ans = 1e18;

  long long curr_ans = 0;
  long long curr_load = 0;
  for (int laps = 0; laps < 2; ++laps) {
    for (int i = 0; i < (int)clock.size(); ++i) {
      curr_ans += curr_load;
      if (clock[i] > target) {
        curr_load += (clock[i] - target);
        clock[i] = target;
      } else if (clock[i] < target) {
        long long diff = target - clock[i];
        if (diff > curr_load) {
          clock[i] += curr_load;
          curr_load = 0;
        } else {
          curr_load -= (target - clock[i]);
          clock[i] = target;
        }
      }
    }
  }
  ans = min(ans, curr_ans);

  curr_ans = 0;
  curr_load = 0;
  for (int laps = 0; laps < 2; ++laps) {
    for (int i = (int)counter_clock.size() - 1; i >= 0; --i) {
      curr_ans += curr_load;
      if (counter_clock[i] > target) {
        curr_load += (counter_clock[i] - target);
        counter_clock[i] = target;
      } else if (counter_clock[i] < target) {
        long long diff = target - counter_clock[i];
        if (diff > curr_load) {
          counter_clock[i] += curr_load;
          curr_load = 0;
        } else {
          curr_load -= (target - counter_clock[i]);
          counter_clock[i] = target;
        }
      }
    }
  }
  ans = min(ans, curr_ans);

  cout << ans << '\n';

  return 0;
}
