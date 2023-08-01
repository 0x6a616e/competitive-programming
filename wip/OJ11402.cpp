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

        int p1 = rsq(left(p), L, (L + R) / 2, i, j);
        int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

        return p1 + p2;
    }

    void pointUpdate(int p, int L, int R, int i, int v) {
        if (L == R && L == i) {
            st[p] = v;
        } else if (i >= L && i <= R) {
            pointUpdate(left(p), L, (L + R) / 2, i, v);
            pointUpdate(right(p), (L + R) / 2 + 1, R, i, v);

            st[p] = st[left(p)] + st[right(p)];
        }
    }

    void push(int p) {
        if (marked[p]) {
            st[left(p)] = st[right(p)] = st[p];
            marked[left(p)] = marked[right(p)] = true;
            marked[p] = false;
        }
    }

    void rangeUpdate(int p, int L, int R, int i, int j, int v) {
        if (L > R) return;
        if (i >= L && j <= R) {
            st[p] = v;
            marked[p] = true;
        } else {
            push(p);
            rangeUpdate(left(p), L, (L + R) / 2, i, j, v);
            rangeUpdate(right(p), L, (L + R) / 2 + 1, i, j, v);
        }
    }

    SegmentTree(vector<int> &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        marked.assign(4 * n, false);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }

    void pointUpdate(int i, int v) {
        pointUpdate(1, 0, n - 1, i, v);
        A[i] = v;
    }

    void rangeUpdate(int i, int j, int v) { rangeUpdate(1, 0, n - 1, i, j, v); }

    void invert(int i, int j) {
        for (int k = i; k <= j; ++k)
            if (A[k])
                pointUpdate(k, 0);
            else
                pointUpdate(k, 1);
    }
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
                st.invert(a, b);
            } else if (op == 'S') {
                ++qc;
                cout << 'Q' << qc << ": " << st.rsq(a, b) << '\n';
            }
        }
    }

    return 0;
}
