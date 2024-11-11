#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int degs, n;
  cin >> degs >> n;

  double rads = (double)degs * PI / 180;

  vector<pair<int, int>> flats(n);
  for (int i = 0; i < n; ++i) {
    cin >> flats[i].first;
    cin >> flats[i].second;
  }

  sort(flats.begin(), flats.end());

  double curr_x = 0.0;
  double sol = 0.0;
  for (int i = 0; i < n; ++i) {
    int x = flats[i].first;
    int h = flats[i].second;
    curr_x = max(curr_x, (double)x);
    double shadow = (double)h / tan(rads);
    double shadow_end = (double)x + shadow;
    if (shadow_end > curr_x) {
      sol += shadow_end - curr_x;
      curr_x = shadow_end;
    }
  }

  cout << fixed << setprecision(5) << sol << endl;

  return 0;
}
