#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> st, A;
    vector<bool> marked;
    int n;

    int left(int p) { return p << 1; }

    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }

    int rsq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return 0;

        if (L >= i && R <= j) return st[p];

        push(p, L, R);

        int p1 = rsq(left(p), L, (L + R) / 2, i, j);
        int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

        return p1 + p2;
    }

    void push(int p, int L, int R) {
        if (marked[p]) {
            int v = (st[p] ? 1 : 0);
            int tm = (L + R) / 2;
            st[left(p)] = v * (tm - L + 1);
            st[right(p)] = v * (R - tm);
            marked[left(p)] = marked[right(p)] = true;
            marked[p] = false;
        }
    }

    void rangeUpdate(int p, int L, int R, int i, int j, int v) {
        if (i > R || j < L) return;
        if (L >= i && R <= j) {
            st[p] = v * (R - L + 1);
            marked[p] = true;
            return;
        }
        push(p, L, R);
        rangeUpdate(left(p), L, (L + R) / 2, i, j, v);
        rangeUpdate(right(p), (L + R) / 2 + 1, R, i, j, v);
        st[p] = st[left(p)] + st[right(p)];
    }

    SegmentTree(vector<int>& _A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        marked.assign(4 * n, false);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }

    void rangeUpdate(int i, int j, int v) { rangeUpdate(1, 0, n - 1, i, j, v); }
};

int main() {
    int n;
    cin >> n;

    for (int _ = 0; _ < n; ++_) {
        cout << "Case " << (_ + 1) << ":\n";

        int m;
        cin >> m;

        string land_string = "";

        int t;
        string p;
        while (m--) {
            cin >> t;
            cin >> p;

            while (t--) land_string += p;
        }

        int s = (int)land_string.size();
        vector<int> land(s);

        for (int i = 0; i < s; ++i) land[i] = land_string[i] - '0';

        SegmentTree st(land);

        int q, a, b;
        char op;

        cin >> q;
        int qc = 0;
        while (q--) {
            cin >> op >> a >> b;

            if (op == 'F') {
                st.rangeUpdate(a, b, 1);
            } else if (op == 'E') {
                st.rangeUpdate(a, b, 0);
            } else if (op == 'I') {
                //  st.invert(a, b);
            } else if (op == 'S') {
                ++qc;
                cout << 'Q' << qc << ": " << st.rsq(a, b) << '\n';
            }
        }
    }

    return 0;
}
