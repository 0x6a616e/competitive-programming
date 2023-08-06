#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> st, A;
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
            st[p] = p1 * p2;
        }
    }

    int rpq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return 1;

        if (L >= i && R <= j) return st[p];

        int p1 = rpq(left(p), L, (L + R) / 2, i, j);
        int p2 = rpq(right(p), (L + R) / 2 + 1, R, i, j);

        return p1 * p2;
    }

    void pointUpdate(int p, int L, int R, int i, int v) {
        if (i == L && i == R) {
            st[p] = v;
        } else if (i >= L && i <= R) {
            pointUpdate(left(p), L, (L + R) / 2, i, v);
            pointUpdate(right(p), (L + R) / 2 + 1, R, i, v);

            st[p] = st[left(p)] * st[right(p)];
        }
    }

    SegmentTree(vector<int>& _A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rpq(int i, int j) { return rpq(1, 0, n - 1, i, j); }

    void pointUpdate(int i, int v) { pointUpdate(1, 0, n - 1, i, v); }
};

int main() {
    int n, k;

    while (cin >> n >> k) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                nums[i] = 1;
            else if (nums[i] < 0)
                nums[i] = -1;
        }

        SegmentTree st(nums);
        char op;
        int a, b;
        for (int i = 0; i < k; ++i) {
            cin >> op >> a >> b;
            if (op == 'C') {
                if (b > 0)
                    b = 1;
                else if (b < 0)
                    b = -1;

                st.pointUpdate(a - 1, b);
            } else if (op == 'P') {
                int res = st.rpq(a - 1, b - 1);
                if (res == 0)
                    cout << '0';
                else if (res > 0)
                    cout << '+';
                else if (res < 0)
                    cout << '-';
            }
        }
        cout << '\n';
    }

    return 0;
}
