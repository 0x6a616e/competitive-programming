#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
        vector<int> bit;  // binary indexed tree
        int n;
        
        FenwickTree(int n) {
                this->n = n + 1;
                bit.assign(n + 1, 0);
        }
        
        FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
                for (int i = 0; i < n; i++) {
                        bit[i] += a[i];
                        int r = i | (i + 1);
                        if (r < n)
                                bit[r] += bit[i];
                }
        }

        void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
                bit[idx] += val;
        }

        void range_add(int l, int r, int val) {
                add(l, val);
                add(r + 1, -val);
        }

        int point_query(int idx) {
                int ret = 0;
                for (++idx; idx > 0; idx -= idx & -idx)
                        ret += bit[idx];
                return ret;
        }
};

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, m, l, r;
        char o;

        cin >> n;

        FenwickTree ft(n + 2);

        cin >> m;

        while (m--) {
                cin >> o;
                if (o == 'C') {
                        cin >> l >> r;
                        ft.range_add(l + 1, r, 1);
                } else {
                        cin >> l;
                        cout << ft.point_query(l + 1) << '\n';
                }
        }
        
        return 0;
}
