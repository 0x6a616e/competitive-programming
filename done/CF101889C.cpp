#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k, n;
  cin >> k >> n;

  vector<bool> exists(k + 1);
  map<int, int> counter1;
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    exists[s] = true;
    ++counter1[s];
  }

  map<int, vector<int>> counter2;
  for (pair<int, int> p : counter1) {
    counter2[p.second].push_back(p.first);
  }

  int missing = 0;
  for (int i = 1; i <= k; ++i)
    if (!exists[i]) ++missing;

  if (missing > 1) {
    cout << "*\n";
    return 0;
  }
  if (missing == 1) {
    int sol = 0;
    for (int i = 1; i <= k && !sol; ++i) {
      if (!exists[i]) sol = i;
    }
    if (counter2.size() == 1 && counter2.begin()->first == 1) {
      cout << "+" << sol << '\n';
      return 0;
    } else if (counter2.size() == 2) {
      auto it1 = counter2.begin();
      auto it2 = next(it1);
      int diff = it2->first - it1->first;
      if (it1->first == 1 && diff == 1 && it2->second.size() == 1) {
        cout << "-" << it2->second[0] << " +" << sol << '\n';
        return 0;
      }
    }
    cout << "*\n";
    return 0;
  }
  if (counter2.size() > 3) {
    cout << "*\n";
    return 0;
  }
  if (counter2.size() == 3) {
    auto it1 = counter2.begin();
    auto it2 = next(it1);
    auto it3 = next(it2);
    if (it2->first - it1->first > 1) {
      cout << "*\n";
      return 0;
    }
    if (it3->first - it2->first > 1) {
      cout << "*\n";
      return 0;
    }
    if (it1->second.size() != 1 || it3->second.size() != 1) {
      cout << "*\n";
      return 0;
    }
    cout << "-" << it3->second[0] << " +" << it1->second[0] << '\n';
    return 0;
  }
  if (counter2.size() == 2) {
    auto it1 = counter2.begin();
    auto it2 = next(it1);
    int diff = it2->first - it1->first;
    if (diff > 2) {
      cout << "*\n";
      return 0;
    }
    if (diff == 2) {
      if (it1->second.size() == 1 && it2->second.size() == 1) {
        cout << "-" << it2->second[0] << " +" << it1->second[0] << '\n';
        return 0;
      } else {
        cout << "*\n";
        return 0;
      }
    }
    if (diff == 1) {
      if (it1->second.size() == 1 || it2->second.size() == 1) {
        if (it1->second.size() == 1) {
          cout << "+" << it1->second[0] << '\n';
          return 0;
        } else {
          cout << "-" << it2->second[0] << '\n';
          return 0;
        }
      } else {
        cout << "*\n";
        return 0;
      }
    }
  }

  cout << "*\n";

  return 0;
}
