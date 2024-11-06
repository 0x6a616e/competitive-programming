#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, c;
  cin >> n >> c;

  queue<string> pendientes;
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    pendientes.push(t);
  }

  pair<int, string> sol = {0, ""};
  map<string, int> counter;
  while (!pendientes.empty()) {
    string t = pendientes.front();
    pendientes.pop();
    bool complete = true;
    for (int i = 0; i < c; ++i) {
      if (t[i] == '*') {
        complete = false;
        for (t[i] = 'a'; t[i] <= 'z'; ++t[i]) {
          pendientes.push(t);
        }
        t[i] = '*';
        break;
      }
    }
    if (!complete) continue;
    ++counter[t];
    if ((counter[t] > sol.F) || (counter[t] == sol.F && t < sol.S)) {
      sol = {counter[t], t};
    }
  }

  cout << sol.S << ' ' << sol.F << '\n';

  return 0;
}
