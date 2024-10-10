// https://codeforces.com/gym/104375/problem/A

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; ++i)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  map<string, int> words;
  int contador = 0;
  REP(i, 0, n) {
    int x;
    cin >> x;
    string name = "";
    REP(j, 0, x) {
      string w;
      cin >> w;
      name += w[0];
    }
    if (words[name] == 1) --contador;
    if (!words[name]++) ++contador;
  }
  cout << contador << '\n';

  return 0;
}
