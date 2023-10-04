#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int N) {
        rank.assign(N, 0);
        parent.assign(N, 0);
        for (int i = 0; i < N; ++i) parent[i] = i;
    }

    int findSet(int i) {
        if (parent[i] == i) return i;

        parent[i] = findSet(parent[i]);

        return parent[i];
    }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);

            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
            }
        }
    }
};

double distancia(int x1, int y1, int x2, int y2) {
    double res = (x2 - x1) * (x2 - x1);
    res += (y2 - y1) * (y2 - y1);
    return sqrt(res);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<pair<int, int>> towns(N);
        for (int i = 0; i < N; ++i) {
            towns[i] = {0, 0};
            cin >> towns[i].first;
            cin >> towns[i].second;
        }

        UnionFind uf(N);

        int M;
        cin >> M;

        int x, y;
        for (int i = 0; i < M; ++i) {
            cin >> x >> y;
            uf.unionSet(x - 1, y - 1);
        }

        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        pair<int, int> p1, p2;
        double dist;
        for (int i = 0; i < N; ++i) {
            p1 = towns[i];
            for (int j = i + 1; j < N; ++j) {
                p2 = towns[j];
                dist = distancia(p1.first, p1.second, p2.first, p2.second);
                pq.push({dist, {i, j}});
            }
        }

        bool flag = false;

        while (!pq.empty()) {
            pair<int, int> p = pq.top().second;
            if (!uf.isSameSet(p.first, p.second)) {
                flag = true;
                uf.unionSet(p.first, p.second);
                cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            }
            pq.pop();
        }

        if (!flag) cout << "No new highways need\n";

        if (t) cout << '\n';
    }

    return 0;
}
