#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string query, query_r;

        while (getline(cin, query) && query != "DONE") {
                for (size_t i = 0; i < query.size(); i++) {
                        if (query[i] == '.' || query[i] == ',' || query[i] == '!' || query[i] == '?' || query[i] == ' ') {
                                query.erase(i, 1);
                                i--;
                        } else {
                                query[i] = tolower(query[i]);
                        }
                }
                query_r = query;

                reverse(query_r.begin(), query_r.end());

                if (query == query_r) {
                        cout << "You won't be eaten!\n";
                } else {
                        cout << "Uh oh..\n";
                }
                
        }
        
        return 0;
}
