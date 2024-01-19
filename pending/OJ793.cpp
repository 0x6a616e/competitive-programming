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
    string linea;

    getline(cin, linea);

    c = stoi(linea);

    getline(cin, linea);

    while (c--) {
        int n;
        getline(cin, linea);
        n = stoi(linea);

        int i, j;
        char op;
        istringstream line_stream;
        UnionFind uf(n + 1);

        pair<int, int> counter = {0, 0};
        while (getline(cin, linea) && linea != "") {
            line_stream.str(linea + '\n');
            line_stream >> op >> i >> j;

            if (op == 'c') {
                uf.UnionSet(i, j);
            } else {
                if (uf.IsSameSet(i, j)) {
                    ++counter.first;
                } else {
                    ++counter.second;
                }
            }
        }
        cout << counter.first << "," << counter.second << '\n';

        if (c > 0) cout << '\n';
    }

    return 0;
}
