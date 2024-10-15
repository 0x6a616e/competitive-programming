#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, int> mii;
typedef vector<int> vi;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  mii left_m;
  vi left_v(n);
  for (int i = 0; i < n; ++i) {
    cin >> left_v[i];
    left_m[left_v[i]] = i;
  }

  mii right_m;
  vi right_v(n);
  for (int i = 0; i < n; ++i) {
    cin >> right_v[i];
    right_m[right_v[i]] = i;
  }

  int sol = 0;
  for (int i = 0; i < n; ++i) {
    if (left_v[i] != (i + 1)) {
      ++sol;
      int pos = left_m[i + 1];
      left_m[i + 1] = i;
      left_m[left_v[i]] = pos;
      left_v[pos] = left_v[i];
      left_v[i] = (i + 1);
    }
    if (right_v[i] != (i + 1)) {
      ++sol;
      int pos = right_m[i + 1];
      right_m[i + 1] = i;
      right_m[right_v[i]] = pos;
      right_v[pos] = right_v[i];
      right_v[i] = (i + 1);
    }
  }

  cout << sol << '\n';

  return 0;
}
