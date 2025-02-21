#include <bits/stdc++.h>

using namespace std;

void solve(bool &solved, map<int, vector<string>> &dict,
           map<char, char> &translator, set<char> &used, vector<string> &words,
           int index) {
  if (solved) {
    return;
  }
  if (index >= (int)words.size()) {
    solved = true;
    return;
  }
  string current = words[index];
  for (string attempt : dict[current.size()]) {
    bool possible = true;
    map<char, char> bkm = translator;
    set<char> bks = used;
    for (int i = 0; i < (int)current.size(); ++i) {
      char c = current[i];
      if (translator.count(c) && translator[c] != attempt[i]) {
        possible = false;
        break;
      }
      if (!translator.count(c) && used.count(attempt[i])) {
        possible = false;
        break;
      }
      used.insert(attempt[i]);
      translator[c] = attempt[i];
    }
    if (possible) {
      solve(solved, dict, translator, used, words, index + 1);
    }
    if (!solved) {
      used = bks;
      translator = bkm;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  map<int, vector<string>> dict;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    dict[s.size()].push_back(s);
  }

  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    vector<string> words;
    {
      stringstream ss(line);
      string word;
      while (ss >> word) {
        words.push_back(word);
      }
    }
    bool solved = false;
    map<char, char> translator = {{' ', ' '}};
    set<char> used;
    solve(solved, dict, translator, used, words, 0);
    if (solved) {
      for (char c : line) {
        cout << translator[c];
      }
    } else {
      for (char c : line) {
        if (c == ' ') {
          cout << c;
        } else {
          cout << '*';
        }
      }
    }
    cout << '\n';
  }

  return 0;
}
