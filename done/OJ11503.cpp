#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> parent, rank, n_s;

    UnionFind(int N) {
        rank.assign(N, 0);
        parent.assign(N, 0);
        n_s.assign(N, 1);
        for (int i = 0; i < N; ++i) parent[i] = i;
    }

    int FindSet(int i) {
        if (parent[i] == i) return i;

        parent[i] = FindSet(parent[i]);

        return parent[i];
    }

    bool IsSameSet(int i, int j) { return FindSet(i) == FindSet(j); }

    void UnionSet(int i, int j) {
        if (!IsSameSet(i, j)) {
            int x = FindSet(i);
            int y = FindSet(j);

            if (rank[x] > rank[y]) {
                parent[y] = x;
                n_s[x] += n_s[y];
            } else {
                parent[x] = y;
                n_s[y] += n_s[x];
                if (rank[x] == rank[y]) ++rank[y];
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int f;
        cin >> f;

        UnionFind uf(1);
        map<string, int> name_map;
        int people_counter = 0;

        string p1, p2;
        for (int i = 0; i < f; ++i) {
            cin >> p1 >> p2;

            if (!name_map[p1]) {
                ++people_counter;
                name_map[p1] = people_counter;
                uf.rank.push_back(0);
                uf.parent.push_back(people_counter);
                uf.n_s.push_back(1);
            }
            if (!name_map[p2]) {
                ++people_counter;
                name_map[p2] = people_counter;
                uf.rank.push_back(0);
                uf.parent.push_back(people_counter);
                uf.n_s.push_back(1);
            }
            uf.UnionSet(name_map[p1], name_map[p2]);
            cout << uf.n_s[uf.FindSet(name_map[p1])] << '\n';
        }
    }

    return 0;
}
