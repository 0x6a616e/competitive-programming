#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    pq.push(a);
  }

  int offset = 0;
  int sol = 0;
  while (!pq.empty()) {
    int curr = pq.top();
    pq.pop();
    if (curr - offset == 1) {
      offset = curr;
      continue;
    }
    sol ^= (curr - offset);
  }

  bool ans;
  if (sol)
    ans = true;
  else
    ans = false;

  if (offset % 2) ans = !ans;

  if (ans)
    cout << "Alicius\n";
  else
    cout << "Bobius\n";

  return 0;
}
