#include <bits/stdc++.h>

using namespace std;

typedef map<int, int> mii;
typedef pair<int, int> pii;

#define F first
#define S second

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  mii contador;
  for (int i = 0; i < 3 * n; ++i) {
    int a;
    cin >> a;
    ++contador[a];
  }

  bool sol = true;
  for (pii p : contador) {
    if (p.S % 3 != 0) sol = false;
  }

  if (sol)
    cout << "N\n";
  else
    cout << "Y\n";

  return 0;
}
