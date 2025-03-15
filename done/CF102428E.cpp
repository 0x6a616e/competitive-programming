#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string b;
  cin >> b;

  int s;
  cin >> s;

  int n = b.size();
  b += b;

  map<int, int> e_right_count;
  {
    int count = 0;
    int l = 0;
    int r = s;
    for (int i = l; i < r; ++i) {
      if (b[i] == 'E') {
        ++count;
      }
    }
    while (l < n) {
      if (b[l] == 'E') {
        e_right_count[l] = count - 1;
      }
      if (b[l++] == 'E') {
        --count;
      }
      if (b[r++] == 'E') {
        ++count;
      }
    }
  }

  map<int, pair<int, int>> p_right_count;
  {
    int l = 0;
    int r = s;
    queue<int> es;
    for (int i = l; i < r; ++i) {
      if (b[i] == 'E') {
        es.push(i);
      }
    }
    while (l < n) {
      if (b[l] == 'P') {
        p_right_count[l] = {(es.empty() ? -1 : es.front()), es.size()};
      }
      if (b[l++] == 'E') {
        es.pop();
      }
      if (b[r++] == 'E') {
        es.push(r - 1);
      }
    }
  }

  long long ans = 0;
  for (pair<int, int> eggfruit : e_right_count) {
    int local_ans = (s - 1) + (s - 1) + 1 - eggfruit.second;
    ans += local_ans;
  }
  for (pair<int, pair<int, int>> persimon : p_right_count) {
    if (persimon.second.first == -1) {
      continue;
    }
    int reach = persimon.first + s - 1;
    int local_ans = reach - persimon.second.first;
    local_ans -= (persimon.second.second - 1);
    ans += local_ans;
  }

  cout << ans << endl;

  return 0;
}
