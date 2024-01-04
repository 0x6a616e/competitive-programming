#include <bits/stdc++.h>

using namespace std;

struct Group {
    int a, b, p;

    Group(int a, int b, int p) {
        this->a = a;
        this->b = b;
        this->p = p;
    }

    bool operator<(Group &g) {
        if (this->a == g.a) return this->b < g.b;
        return this->a < g.a;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n], b[n], c[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) c[i] = i;

        vector<Group> groups;
        for (int i = 0; i < n; ++i) groups.push_back(Group(a[i], b[i], i));
        sort(groups.begin(), groups.end());

        bool posible = true;
        for (int i = 1; i < n; ++i)
            if (groups[i].a < groups[i - 1].a) posible = false;

        for (int i = 1; i < n; ++i)
            if (groups[i].b < groups[i - 1].b) posible = false;

        if (!posible) cout << "-1\n";
        if (!posible) continue;

        vector<pair<int, int>> sol;
        int curr = 0;
        for (Group g : groups) {
            int looking = -1;
            for (int i = 0; i < n && looking == -1; ++i)
                if (c[i] == g.p) looking = i;
            if (curr != looking) {
                sol.push_back({curr + 1, looking + 1});
                swap(c[curr], c[looking]);
            }
            ++curr;
        }

        cout << sol.size() << "\n";
        for (pair<int, int> s : sol) cout << s.first << " " << s.second << "\n";
    }

    return 0;
}
