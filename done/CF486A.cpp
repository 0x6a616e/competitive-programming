#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  unsigned long long n;
  cin >> n;
  string out = "";
  if (n % 2 != 0) {
    out = "-";
    ++n;
  }

  n /= 2;
  cout << out << n << endl;

  return 0;
}
