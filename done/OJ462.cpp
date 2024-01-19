// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=403

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        char suit, card;

        while (cin >> card >> suit) {
                map<char, set<char>> cards;
                map<char, bool> stopped;
                map<char, set<char>>::iterator it;
                pair<int, int> total = { 0, 0 };

                cards[suit].insert(card);
                if (card == 'A') {
                        total.first += 4;
                } else if (card == 'K') {
                        total.first += 3;
                } else if (card == 'Q') {
                        total.first += 2;
                } else if (card == 'J') {
                        total.first += 1;
                }

                for (int i = 0; i < 12; i++) {
                        cin >> card >> suit;
                        cards[suit].insert(card);
                        if (card == 'A') {
                                total.first += 4;
                        } else if (card == 'K') {
                                total.first += 3;
                        } else if (card == 'Q') {
                                total.first += 2;
                        } else if (card == 'J') {
                                total.first += 1;
                        }
                }

                // Rule 2
                for (it = cards.begin(); it != cards.end(); it++) {
                        if (it->second.size() == 1 && it->second.find('K') != it->second.end()) {
                                total.first--;
                        }
                }

                // Rule 3
                for (it = cards.begin(); it != cards.end(); it++) {
                        if ((it->second.size() == 1 || it->second.size() == 2) && it->second.find('Q') != it->second.end()) {
                                total.first--;
                        }
                }

                // Rule 4
                for (it = cards.begin(); it != cards.end(); it++) {
                        if ((it->second.size() == 1 || it->second.size() == 2 || it->second.size() == 3) && it->second.find('J') != it->second.end()) {
                                total.first--;
                        }
                }

                // Rule 5
                for (it = cards.begin(); it != cards.end(); it++) {
                        if (it->second.size() == 2) {
                                total.second++;
                        }
                }

                // Rule 6
                for (it = cards.begin(); it != cards.end(); it++) {
                        if (it->second.size() == 1) {
                                total.second += 2;
                        }
                }

                // Rule 7
                for (char s: { 'S', 'H', 'D', 'C' }) {
                        if (cards[s].size() == 0) {
                                total.second += 2;
                        }
                        if (cards[s].find('A') != cards[s].end()) {
                                stopped[s] = true;
                        }
                        if (cards[s].find('K') != cards[s].end() && cards[s].size() > 1) {
                                stopped[s] = true;
                        }
                        if (cards[s].find('Q') != cards[s].end() && cards[s].size() > 2) {
                                stopped[s] = true;
                        }
                }

                if (total.first + total.second < 14) {
                        cout << "PASS\n";
                } else {
                        if (total.first >= 16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C']) {
                                cout << "BID NO-TRUMP\n";
                        } else {
                                char bid = 'S';
                                for (char s: { 'S', 'H', 'D', 'C' }) {
                                        if (cards[s].size() > cards[bid].size()) {
                                                bid = s;
                                        }
                                }
                                cout << "BID " << bid << '\n';
                        }
                }
        }
        
        return 0;
}
