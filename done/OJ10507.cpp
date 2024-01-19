#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        set<char> sleeping, awake;
        queue<char> pending;

        int m;
        cin >> m;

        string line;
        cin >> line;

        for (char c : line) awake.insert(c);

        map<char, vector<char>> ady_list;
        for (int i = 0; i < m; ++i) {
            cin >> line;
            if (!awake.count(line[0])) sleeping.insert(line[0]);
            if (!awake.count(line[1])) sleeping.insert(line[1]);
            ady_list[line[0]].push_back(line[1]);
            ady_list[line[1]].push_back(line[0]);
        }

        int counter = 0;
        bool cambio = true;

        while (!sleeping.empty() && cambio) {
            ++counter;
            cambio = false;

            for (char s : sleeping) {
                int connected = 0;
                for (char c : ady_list[s])
                    if (awake.count(c)) ++connected;

                if (connected >= 3) pending.push(s);
            }

            while (!pending.empty()) {
                cambio = true;
                char a = pending.front();
                sleeping.erase(a);
                awake.insert(a);
                pending.pop();
            }
        }

        if (awake.size() == n)
            cout << "WAKE UP IN, " << counter << ", YEARS\n";
        else
            cout << "THIS BRAIN NEVER WAKES UP\n";
    }

    return 0;
}
