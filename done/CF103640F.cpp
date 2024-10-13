#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {
 private:
  vi p, rank, setSize;
  int numSets;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;         // i and j are in same set
    int x = findSet(i), y = findSet(j);  // find both rep items
    if (rank[x] > rank[y]) swap(x, y);   // keep x ’shorter’ than y
    p[x] = y;                            // set x under y
    if (rank[x] == rank[y]) ++rank[y];   // optional speedup
    setSize[y] += setSize[x];            // combine set sizes at y
    --numSets;                           // a union reduces numSets
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  UnionFind uf(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a == n || b == n) continue;
    uf.unionSet(a, b);
  }

  for (int i = 1; i <= n; ++i) {
    if (uf.isSameSet(i, n - 1))
      cout << 'B';
    else
      cout << 'A';
  }
  cout << '\n';

  return 0;
}
