#include <bits/stdc++.h>

using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

bool validate(vector<P> p) {
  for (int s1 = 0; s1 < 4; ++s1) {
    for (int s2 = s1 + 1; s2 < 4; ++s2) {
      for (int pi = s2 + 1; pi < 4; ++pi) {
        C cp = (conj(p[pi] - p[s1]) * (p[pi] - p[s2])).Y;
        if (cp == 0) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<P> points(n);
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    points[i] = {x, y};
  }

  long long ans = 0;
  vector<P> p(4);
  for (int i1 = 0; i1 < n; ++i1) {
    p[0] = points[i1];
    for (int i2 = i1 + 1; i2 < n; ++i2) {
      p[1] = points[i2];
      for (int i3 = i2 + 1; i3 < n; ++i3) {
        p[2] = points[i3];
        for (int i4 = i3 + 1; i4 < n; ++i4) {
          p[3] = points[i4];
          if (validate(p)) {
            ++ans;
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
