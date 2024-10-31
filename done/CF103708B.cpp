#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int INF = 1e6;

ll next2Power(long long n) {
  --n;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;
  ++n;
  return n;
}

void ett(vvi &a, vi &p, vi &h, vll &l, vll &r, vi &et, int node, int height,
         int prev) {
  p[node] = prev;
  l[node] = (ll)et.size();
  et.push_back(node);
  h.push_back(height);
  for (int n : a[node]) {
    if (n == prev) continue;
    ett(a, p, h, l, r, et, n, height + 1, node);
  }
  r[node] = (ll)et.size();
  et.push_back(node);
  h.push_back(height);
}

struct SegmentTree {
  vi A;
  vpll st;
  SegmentTree(vi &a) {
    A = a;
    st.resize(A.size() * 2);
    build();
  }

  ll l(ll p) { return p << 1; }
  ll r(ll p) { return (p << 1) + 1; }

  void build() {
    ll n = (ll)A.size();
    for (ll i = n; i < (ll)st.size(); ++i) {
      st[i] = {A[i - n], i - n};
    }
    for (ll i = n - 1; i > 0; --i) {
      st[i] = min(st[l(i)], st[r(i)]);
    }
  }

  void update(ll p, ll i, ll L, ll R) {
    if (i < L || i > R) return;
    if (L == R) {
      st[p] = {A[L], L};
      return;
    }
    ll M = (L + R) / 2;
    update(l(p), i, L, M);
    update(r(p), i, M + 1, R);
    st[p] = min(st[l(p)], st[r(p)]);
  }

  void update(ll i, int v) {
    A[i] = v;
    update(1, i, 0, (ll)A.size() - 1);
  }

  pll RMQ(int p, ll i, ll j, ll L, ll R) {
    if (L > j || R < i) return {INF, INF};
    if (L >= i && R <= j) return st[p];
    ll M = (L + R) / 2;
    pll izq = RMQ(l(p), i, j, L, M);
    pll der = RMQ(r(p), i, j, M + 1, R);
    return min(izq, der);
  }

  pll RMQ(ll i, ll j) { return RMQ(1, i, j, 0, (ll)A.size() - 1); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<vi> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vi et;
  vi height;
  vll left(n + 1);
  vll right(n + 1);
  vi parent(n + 1);
  ett(adj, parent, height, left, right, et, 1, 0, 0);

  {
    ll ideal_size = next2Power((long long)et.size());
    et.resize(ideal_size, 0);
    height.resize(ideal_size, INF);
  }

  SegmentTree st(height);
  st.update(left[1], INF);
  st.update(right[1], INF);
  set<int> next_node = {1};
  vi memo(n + 1, 0);
  while (!next_node.empty()) {
    int node = *next_node.begin();
    next_node.erase(node);
    cout << node << ' ';
    // int offset = 0;
    int curr_k = k;
    do {
      if (memo[node] >= curr_k) break;
      memo[node] = curr_k;
      ll i = left[node];
      ll j = right[node];
      int h = height[i];
      while (true) {
        pll rmq = st.RMQ(i, j);
        if (rmq.first - h > curr_k) break;
        int curr_node = et[rmq.second];
        next_node.insert(curr_node);
        st.update(rmq.second, INF);
      }

      --curr_k;
      node = parent[node];
    } while (node != 0 && curr_k);
  }

  return 0;
}
