#include <bits/stdc++.h>

using namespace std;

bool gana(vector<vector<bool>> &carta) {
        for (int i = 0; i < 5; i++) {
                if (carta[i][0] && carta[i][1] && carta[i][2] && carta[i][3] && carta[i][4]) {
                        return true;
                }
                if (carta[0][i] && carta[1][i] && carta[2][i] && carta[3][i] && carta[4][i]) {
                        return true;
                }
        }
        if (carta[0][0] && carta[1][1] && carta[2][2] && carta[3][3] && carta[4][4]) {
                return true;
        }
        if (carta[4][0] && carta[3][1] && carta[2][2] && carta[1][3] && carta[0][4]) {
                return true;
        }
        return false;
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);
        
        int n;

        cin >> n;

        while (n--) {
                int num;
                bool leyendo = true;
                map<int, pair<int, int>> posiciones;
                vector<vector<bool>> carta(5, vector<bool> (5));
                carta[2][2] = true;
                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                                if (i == 2 && j == 2) {
                                        continue;
                                }
                                cin >> num;
                                posiciones[num] = { i + 1, j + 1 };
                        }
                }
                
                for (int i = 0; i < 75; i++) {
                        cin >> num;
                        if (posiciones[num].first && posiciones[num].second && leyendo) {
                                carta[posiciones[num].first - 1][posiciones[num].second - 1] = true;
                                if (gana(carta)) {
                                        leyendo = false;
                                        cout << "BINGO after " << (i + 1) << " numbers announced\n";
                                }
                        }
                }
        }
        
        return 0;
}
