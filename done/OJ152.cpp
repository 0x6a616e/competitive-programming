#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> trio;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<trio> coords;
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (!a && !b && !c) {
      break;
    }
    coords.push_back({a, b, c});
  }

  vector<int> sol(10, 0);
  for (int i = 0; i < (int)coords.size(); ++i) {
    double dist = 11.0;
    for (int j = 0; j < (int)coords.size(); ++j) {
      if (i == j) {
        continue;
      }
      double curr = sqrt(pow(get<0>(coords[i]) - get<0>(coords[j]), 2) +
                         pow(get<1>(coords[i]) - get<1>(coords[j]), 2) +
                         pow(get<2>(coords[i]) - get<2>(coords[j]), 2));

      dist = min(dist, curr);
    }
    int d = (int)dist;
    if (d >= 10)
      continue;
    ++sol[d];
  }
  for (int i : sol) {
    cout << setw(4) << setfill(' ') << i;
  }
  cout << '\n';

  return 0;
}
