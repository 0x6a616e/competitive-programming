#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<long long>> mat(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<pair<int, int>> corners = {
      {0, 0}, {0, n - 1}, {n - 1, n - 1}, {n - 1, 0}};
  vector<pair<int, int>> changes = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  long long ans = 0;

  for (int i = 0; i < (int)corners.size(); ++i) {
    int jump = n - 1;
    pair<int, int> position = corners[i];
    int ci = i;
    long long sum = mat[position.first][position.second];
    ans = max(ans, sum);
    int counter = 0;
    int limit = 3;
    while (jump > 0) {
      for (int j = 0; j < jump; ++j) {
        position.first += changes[ci].first;
        position.second += changes[ci].second;
        sum = max(mat[position.first][position.second],
                  sum + mat[position.first][position.second]);
        ans = max(ans, sum);
      }
      ci = (ci + 1) % 4;
      ++counter;
      if (counter == limit) {
        limit = 2;
        counter = 0;
        --jump;
      }
    }
  }

  corners = {{0, 0}, {n - 1, 0}, {n - 1, n - 1}, {0, n - 1}};
  changes = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  for (int i = 0; i < (int)corners.size(); ++i) {
    int jump = n - 1;
    pair<int, int> position = corners[i];
    int ci = i;
    long long sum = mat[position.first][position.second];
    ans = max(ans, sum);
    int counter = 0;
    int limit = 3;
    while (jump > 0) {
      for (int j = 0; j < jump; ++j) {
        position.first += changes[ci].first;
        position.second += changes[ci].second;
        sum = max(mat[position.first][position.second],
                  sum + mat[position.first][position.second]);
        ans = max(ans, sum);
      }
      ci = (ci + 1) % 4;
      ++counter;
      if (counter == limit) {
        limit = 2;
        counter = 0;
        --jump;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
