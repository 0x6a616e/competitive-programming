#include <bits/stdc++.h>

using namespace std;

bool abs_sort(int a, int b) { return abs(a) < abs(b); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  map<int, set<int>> requests;
  for (int i = 0; i < n; ++i) {
    int student, count;
    cin >> student >> count;
    for (int j = 0; j < count; ++j) {
      int course;
      cin >> course;
      requests[student].insert(course);
    }
  }

  map<int, vector<int>> mistakes;
  int not_requested = 0;
  int missed = 0;
  for (int i = 0; i < m; ++i) {
    int student, count;
    cin >> student >> count;
    for (int j = 0; j < count; ++j) {
      int course;
      cin >> course;
      if (!requests[student].count(course)) {
        ++not_requested;
        mistakes[student].push_back(-1 * course);
      }
      requests[student].erase(course);
    }
  }
  for (pair<int, set<int>> request : requests) {
    for (int course : request.second) {
      ++missed;
      mistakes[request.first].push_back(course);
    }
  }

  if (mistakes.size() == 0) {
    cout << "GREAT WORK! NO MISTAKES FOUND!\n";
  } else {
    for (pair<int, vector<int>> mistake : mistakes) {
      sort(mistake.second.begin(), mistake.second.end(), abs_sort);
      cout << mistake.first;
      for (int course : mistake.second) {
        cout << ' ' << (course > 0 ? "+" : "") << course;
      }
      cout << '\n';
    }
    cout << "MISTAKES IN " << mistakes.size() << " STUDENTS: " << not_requested
         << " NOT REQUESTED, " << missed << " MISSED\n";
  }

  return 0;
}
