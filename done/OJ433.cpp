#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> explore(vector<vector<vector<bool>>> &templates,
                                       vector<vector<bool>> &input) {
  vector<vector<pair<int, int>>> ans(9);
  for (int i = 0; i < 27; i += 3) {
    for (int num = 0; num < 10; ++num) {
      bool possible = true;
      pair<int, int> curr = {0, num};
      for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
          if (input[y][i + x] && !templates[num][y][x]) {
            possible = false;
          }
          if (templates[num][y][x] && !input[y][i + x]) {
            ++curr.first;
          }
        }
      }
      if (possible) {
        ans[i / 3].push_back(curr);
      }
    }
    sort(ans[i / 3].begin(), ans[i / 3].end());
  }
  return ans;
}

bool validate(vector<int> &query) {
  int ans = 0;
  for (int i = 0; i < 9; ++i) {
    ans += query[i] * (9 - i);
  }
  return ans % 11 == 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<vector<vector<bool>>> templates = {
      {
          {0, 1, 0},
          {1, 0, 1},
          {1, 1, 1},
      },
      {
          {0, 0, 0},
          {0, 0, 1},
          {0, 0, 1},
      },
      {
          {0, 1, 0},
          {0, 1, 1},
          {1, 1, 0},
      },
      {
          {0, 1, 0},
          {0, 1, 1},
          {0, 1, 1},
      },
      {
          {0, 0, 0},
          {1, 1, 1},
          {0, 0, 1},
      },
      {
          {0, 1, 0},
          {1, 1, 0},
          {0, 1, 1},
      },
      {
          {0, 1, 0},
          {1, 1, 0},
          {1, 1, 1},
      },
      {
          {0, 1, 0},
          {0, 0, 1},
          {0, 0, 1},
      },
      {
          {0, 1, 0},
          {1, 1, 1},
          {1, 1, 1},
      },
      {
          {0, 1, 0},
          {1, 1, 1},
          {0, 1, 1},
      },
  };

  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    string line;
    vector<vector<bool>> input(3, vector<bool>(27, false));
    for (int i = 0; i < 3; ++i) {
      getline(cin, line);
      for (int j = 0; j < 27; ++j) {
        input[i][j] = (line[j] != ' ');
      }
    }
    vector<vector<pair<int, int>>> options = explore(templates, input);
    int invalid = 0;
    int invalid_idx = -1;
    for (int i = 0; i < 9; ++i) {
      if (options[i][0].first != 0) {
        ++invalid;
        invalid_idx = i;
      }
    }
    int solution_count = 0;
    vector<int> sol;
    vector<int> final_sol;
    for (int i = 0; i < 9; ++i) {
      sol.push_back(options[i][0].second);
    }
    if (invalid == 0) {
      if (validate(sol)) {
        final_sol = sol;
        ++solution_count;
      } else {
        for (int i = 0; i < 9; ++i) {
          for (pair<int, int> option : options[i]) {
            sol[i] = option.second;
            if (validate(sol)) {
              final_sol = sol;
              ++solution_count;
            }
          }
          sol[i] = options[i][0].second;
        }
      }
    } else if (invalid == 1) {
      for (pair<int, int> option : options[invalid_idx]) {
        sol[invalid_idx] = option.second;
        if (validate(sol)) {
          final_sol = sol;
          ++solution_count;
        }
      }
    }

    if (solution_count > 1) {
      cout << "ambiguous";
    } else if (solution_count == 1) {
      for (int i = 0; i < (int)final_sol.size(); ++i) {
        cout << final_sol[i];
      }
    } else {
      cout << "failure";
    }
    cout << '\n';
  }

  return 0;
}
