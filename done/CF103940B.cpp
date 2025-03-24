#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<int> palindromes = {1, 3};
  for (int i = 3; i < 32; ++i) {
    int base = (1 << (i - 1)) + 1;
    for (int j = 0; j < (1 << ceil(i - 2, 2)); ++j) {
      int curr = base;
      for (int k = 0; k < (i - 2) / 2; ++k) {
        if (j & (1 << k)) {
          curr += (1 << (k + 1));
          curr += (1 << (i - 2 - k));
        }
      }
      if (i % 2 == 1 && (j & (1 << ((i - 2) / 2)))) {
        curr += 1 << ceil(i - 2, 2);
      }
      palindromes.push_back(curr);
    }
  }
  sort(palindromes.begin(), palindromes.end());

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    auto ita = lower_bound(palindromes.begin(), palindromes.end(), a);
    auto itb = upper_bound(palindromes.begin(), palindromes.end(), b);
    cout << distance(ita, itb) << endl;
  }

  return 0;
}
