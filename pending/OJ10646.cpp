// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=18&page=show_problem&problem=1587

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        for (int i = 0; i < t; i++) {
                int Y = 0;
                vector<char> pile(27), pile_s(27), hand(25), hand_s(25);

                for (int j = 0; j < 27; j++) {
                        cin >> pile[j];
                        cin >> pile_s[j];
                }

                for (int j = 0; j < 25; j++) {
                        cin >> hand[j];
                        cin >> hand_s[j];
                }

                int index = 26;

                for (int j = 0; j < 3; j++) {
                        int X;
                        if (pile[index] == 'A' || pile[index] == 'K' || pile[index] == 'Q' || pile[index] == 'J' || pile[index] == 'T') {
                                X = 10;
                        } else {
                                X = (pile[index] - '0');
                        }
                        Y += X;
                        index--;
                        index -= (10 - X);
                }

                Y--;

                if (Y > index) {
                        cout << "Case " << (i + 1) << ": " << hand[Y - index - 1] << hand_s[Y - index - 1] << '\n';
                } else {
                        cout << "Case " << (i + 1) << ": " << pile[index] << pile_s[index] << '\n';
                }
        }
        
        return 0;
}
