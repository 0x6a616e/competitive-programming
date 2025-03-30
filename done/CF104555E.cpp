#include <bits/stdc++.h>

using namespace std;

const int MAX_FI = 1000000;

int digitSum(int n) {
  int ans = 0;
  while (n) {
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> count(MAX_FI + 1, 0);

  int max_fi = 0;
  for (int i = 0; i < n; ++i) {
    int fi;
    cin >> fi;
    ++count[fi];
    max_fi = max(max_fi, fi);
  }
  int curr = max_fi;
  while (curr > 0) {
    count[curr - digitSum(curr)] += count[curr];
    --curr;
  }

  int i = max_fi;
  while (i) {
    if (k <= count[i]) {
      break;
    }
    k -= count[i--];
  }
  cout << digitSum(i) << '\n';

  return 0;
}
