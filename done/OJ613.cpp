#include <bits/stdc++.h>

using namespace std;

string transform(string orig) {
  vector<int> counter(10);
  for (char c : orig) {
    int n = c - '0';
    ++counter[n];
  }
  string out = "";
  for (int i = 0; i < 10; ++i) {
    if (counter[i]) {
      string cant = to_string(counter[i]);
      string num = to_string(i);
      out += cant + num;
    }
  }
  return out;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string num;
  while (cin >> num) {
    if (num == "-1")
      break;
    int iteration = 0;
    string curr = num;
    map<string, int> past;
    while (true) {
      if (iteration >= 15) {
        cout << num << " can not be classified after 15 iterations";
        break;
      }
      string prev = curr;
      curr = transform(curr);
      if (prev == curr) {
        if (iteration == 0) {
          cout << num << " is self-inventorying";
        } else {
          cout << num << " is self-inventorying after " << iteration
               << " steps";
        }
        break;
      }
      if (past.count(curr)) {
        cout << num << " enters an inventory loop of length "
             << (iteration - past[curr]);
        break;
      }
      past[curr] = iteration;
      ++iteration;
    }
    cout << endl;
  }

  return 0;
}
