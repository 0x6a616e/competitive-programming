#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m;
  cin >> m;
  while (m--) {
    int n;
    cin >> n;
    int rem = n;

    vector<int> sol(n, 0);
    int max_i;
    for (max_i = 1; max_i <= rem; ++max_i) {
      sol[max_i] = 1;
      rem -= max_i;
    }
    --max_i;
    if (rem) {
      --sol[max_i - rem + 1];
      ++sol[++max_i];
    }

    if (sol[1]) {
      --sol[1];
      for (int i = 1; i <= max_i; ++i) {
        if (!sol[i] || sol[i + 1]) {
          continue;
        }
        --sol[i];
        ++sol[i + 1];
        max_i = max(max_i, i + 1);
        break;
      }
    }

    string sep = "";
    for (int i = 0; i <= max_i; ++i) {
      if (sol[i]) {
        cout << sep << i;
        sep = " ";
      }
    }
    cout << '\n';
    if (m) {
      cout << '\n';
    }
  }

  return 0;
}
