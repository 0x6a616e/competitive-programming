#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int N) {
        rank.assign(N, 0);
        parent.assign(N, 0);
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

            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
            }
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;

    cin >> c;

    while (c--) {
        string line;
        UnionFind uf(26);
        unordered_set<int> connected, parents;
        int l1, l2;

        while (cin >> line && line[0] != '*') {
            l1 = line[1] - 'A';
            l2 = line[3] - 'A';
            uf.UnionSet(l1, l2);
            connected.insert(l1);
            connected.insert(l2);
        }
        cin >> line;
        int acorns = 0;

        for (size_t i = 0; i < line.size(); i += 2) {
            l1 = line[i] - 'A';
            if (connected.count(l1)) {
                parents.insert(uf.FindSet(l1));
            } else {
                ++acorns;
            }
        }

        cout << "There are " << parents.size() << " tree(s) and " << acorns
             << " acorn(s).\n";
    }

    return 0;
}
