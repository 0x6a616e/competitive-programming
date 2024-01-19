#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string game;

        while (getline(cin, game) && game != "Game Over") {
                int score, i, frames;
                score = i = frames = 0;

                while (frames < 10) {
                        if (game[i] == 'X') {
                                score += 10;
                                score += (game[i + 2] == 'X' ? 10 : (game[i + 2] - '0'));
                                if (game[i + 4] == 'X') {
                                        score += 10;
                                } else if (game[i + 4] == '/') {
                                        score += (10 - (game[i + 2] - '0'));
                                } else {
                                        score += (game[i + 4] - '0');
                                }
                                frames++;
                                i += 2;
                        } else {
                                if (game[i + 2] == '/') {
                                        score += 10;
                                        score += (game[i + 4] == 'X' ? 10 : (game[i + 4] - '0'));
                                } else {
                                        score += ((game[i] - '0') + (game[i + 2] - '0'));
                                }
                                frames++;
                                i += 4;
                        }
                }

                cout << score << '\n';
        }
        
        return 0;
}
