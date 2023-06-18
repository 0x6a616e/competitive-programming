#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;
        string frase;

        cin >> t;

        getline(cin, frase);
        getline(cin, frase);

        while (t--) {
                vector<string> frases, frases_p;
                while (getline(cin, frase) && frase != "") {
                        frases.push_back(frase);
                }

                sort(frases.begin(), frases.end());

                for (size_t i = 0; i < frases.size(); i++) {
                        frase = frases[i];
                        for (size_t j = 0; j < frase.size(); j++) {
                                if (frase[j] == ' ') {
                                        frase.erase(j, 1);
                                        j--;
                                }
                        }
                        sort(frase.begin(), frase.end());
                        frases_p.push_back(frase);
                }

                for (size_t i = 0; i < frases.size(); i++) {
                        for (size_t j = i + 1; j < frases.size(); j++) {
                                if (frases_p[i] == frases_p[j]) {
                                        cout << frases[i] << " = " << frases[j] << '\n';
                                }
                        }
                }

                if (t > 0) {
                        cout << '\n';
                }
        }
        
        return 0;
}
