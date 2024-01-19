#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        string query, query_r, query_v;

        getline(cin, query);

        for (int i = 0; i < t; i++) {
                getline(cin, query);
                for (size_t j = 0; j < query.size(); j++) {
                        if (query[j] == ' ' || query[j] == ',' || query[j] == '.' || query[j] == '?' || query[j] == '!' || query[j] == '(' || query[j] == ')') {
                                query.erase(j, 1);
                                j--;
                        }
                }

                query_r = query;
                reverse(query_r.begin(), query_r.end());

                int s = sqrt(query.size());

                query_v = "";
                if (s * s == query.size() && query == query_r) {
                        for (int j = 0; j < s; j++) {
                                for (size_t k = j; k < query.size(); k += s) {
                                        query_v += query[k];
                                }
                        }

                        query_r = query_v;
                        reverse(query_r.begin(), query_r.end());
                }

                cout << "Case #" << (i + 1) << ":\n";
                if (query == query_v && query_v == query_r) {
                        cout << s << '\n';
                } else {
                        cout << "No magic :(\n";
                }

        }
        
        return 0;
}
