#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  int mat[100][100];
  int dist1[100][100];
  int dist2[100][100];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      dist1[i][j] = mat[i][j];
      dist2[i][j] = mat[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
      }
    }
  }

  bool coherent = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist1[i][j] < mat[i][j]) {
        coherent = false;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      dist2[i][j] = INF;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) {
          continue;
        }
        dist2[i][j] = min(dist2[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  if (!coherent) {
    cout << "-1\n";
  } else {
    int sol = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (dist1[i][j] == dist2[i][j]) {
          ++sol;
        }
      }
    }
    cout << sol << '\n';
  }

  return 0;
}
