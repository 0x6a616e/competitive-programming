#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; ++i)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> cards(14, 4);
  int j1, j2;
  cin >> j1 >> j2;
  int m1, m2;
  cin >> m1 >> m2;

  --cards[j1];
  --cards[j2];
  --cards[m1];
  --cards[m2];

  int tj = min(10, j1) + min(10, j2);
  int tm = min(10, m1) + min(10, m2);

  REP(i, 0, n) {
    int card;
    cin >> card;
    --cards[card];
    tj += min(10, card);
    tm += min(10, card);
  }

  int sol = -1;
  REP(i, 1, 14) {
    if (cards[i] == 0) continue;
    int val = min(10, i);
    if (tm + val == 23) {
      sol = i;
      break;
    }
    if (tj + val > 23 && tm + val < 23) {
      sol = i;
      break;
    }
  }

  cout << sol << '\n';

  return 0;
}
