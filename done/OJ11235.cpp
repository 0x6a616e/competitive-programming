#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> st, A;
    int n;

    int left(int p) { return p << 1; }

    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] > A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;

        if (L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;

        if (p2 == -1) return p1;

        return (A[p1] > A[p2]) ? p1 : p2;
    }

    SegmentTree(vector<int> &_A) {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int main() {
    int n;

    while (cin >> n && n) {
        int q;
        cin >> q;

        vector<int> nums(n), freqs(n, 1);
        unordered_map<int, pair<int, int>> start_end;

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (i > 0)
                if (nums[i] == nums[i - 1]) freqs[i] += freqs[i - 1];
            if (start_end.count(nums[i]))
                start_end[nums[i]].second = i;
            else
                start_end[nums[i]] = {i, i};
        }

        SegmentTree st(freqs);
        int i, j;

        for (int qn = 0; qn < q; ++qn) {
            cin >> i >> j;
            --i;
            --j;

            int first_n = nums[i];
            int last_n = nums[j];

            int izq_n = min(start_end[first_n].second, j) - i + 1;
            int der_n = j - max(start_end[last_n].first, i) + 1;
            int mid_n = 0;

            int izq = start_end[last_n].first - 1;
            int der = start_end[first_n].second + 1;

            if (der <= izq) mid_n = freqs[st.rmq(der, izq)];

            cout << max({izq_n, der_n, mid_n}) << '\n';
        }
    }

    return 0;
}
