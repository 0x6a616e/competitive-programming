#include <bits/stdc++.h>

using namespace std;

struct Page {
        vector<vector<char>> grid;
        map<char, vector<pair<int, int>>> letrasC5;

        Page() {
                grid.resize(60, vector<char> (60, '.'));
                letrasC5['A'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 0 }, { 4, 4 } };
                letrasC5['B'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 0 }, { 3, 4 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['C'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 3, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
                letrasC5['D'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['E'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 3, 0 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
                letrasC5['F'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 3, 0 }, { 4, 0 } };
                letrasC5['G'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 2, 0 }, { 2, 3 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['H'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 0 }, { 4, 4 } };
                letrasC5['I'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 2 }, { 2, 2 }, { 3, 2 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
                letrasC5['J'] = { { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 3 }, { 2, 3 }, { 3, 0 }, { 3, 3 }, { 4, 1 }, { 4, 2 } };
                letrasC5['K'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 3 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 3, 0 }, { 3, 3 }, { 4, 0 }, { 4, 4 } };
                letrasC5['L'] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
                letrasC5['M'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 1 }, { 1, 3 }, { 1, 4 }, { 2, 0 }, { 2, 2 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 0 }, { 4, 4 } };
                letrasC5['N'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 1 }, { 1, 4 }, { 2, 0 }, { 2, 2 }, { 2, 4 }, { 3, 0 }, { 3, 3 }, { 3, 4 }, { 4, 0 }, { 4, 4 } };
                letrasC5['O'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['P'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 0 }, { 4, 0 } };
                letrasC5['Q'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 4 }, { 3, 0 }, { 3, 3 }, { 3, 4 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
                letrasC5['R'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 0 }, { 3, 3 }, { 4, 0 }, { 4, 4 } };
                letrasC5['S'] = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 4 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['T'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 0 }, { 1, 2 }, { 1, 4 }, { 2, 2 }, { 3, 2 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['U'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 4 }, { 3, 0 }, { 3, 4 }, { 4, 1 }, { 4, 2 }, { 4, 3 } };
                letrasC5['V'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 4 }, { 2, 1 }, { 2, 3 }, { 3, 1 }, { 3, 3 }, { 4, 2 } };
                letrasC5['W'] = { { 0, 0 }, { 0, 4 }, { 1, 0 }, { 1, 4 }, { 2, 0 }, { 2, 2 }, { 2, 4 }, { 3, 0 }, { 3, 1 }, { 3, 3 }, { 3, 4 }, { 4, 0 }, { 4, 4 } };
                letrasC5['X'] = { { 0, 0 }, { 0, 4 }, { 1, 1 }, { 1, 3 }, { 2, 2 }, { 3, 1 }, { 3, 3 }, { 4, 0 }, { 4, 4 } };
                letrasC5['Y'] = { { 0, 0 }, { 0, 4 }, { 1, 1 }, { 1, 3 }, { 2, 2 }, { 3, 2 }, { 4, 2 } };
                letrasC5['Z'] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 3 }, { 2, 2 }, { 3, 1 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } };
        }

        void insert(string font, int row, int col, string text) {
                if (font == "C1") {
                        for (int i = 0; i < (int) text.size(); i++) {
                                if (text[i] != ' ' && col + i < 60) {
                                        grid[row][col + i] = text[i];
                                }
                        }
                } else if (font == "C5") {
                        for (int i = 0; i < (int) text.size(); i++) {
                                for (pair<int, int> xy: letrasC5[text[i]]) {
                                        if (row + xy.first < 60 && col + xy.second < 60 && col + xy.second >= 0) {
                                                grid[row + xy.first][col + xy.second] = '*';
                                        }
                                }
                                col += 6;
                        }
                }
        }

        void print() {
                for (int i = 0; i < 60; i++) {
                        for (int j = 0; j < 60; j++) {
                                cout << grid[i][j];
                        }
                        cout << '\n';
                }
                cout << '\n';

                for (int i = 0; i < 60; i++) {
                        cout << '-';
                }
                cout << '\n';
        }

        void reset() {
                grid.clear();
                grid.resize(60, vector<char> (60, '.'));
        }
};

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string operation, font, text, word;
        int row, col;
        Page pagina;

        while (cin >> operation) {
                if (operation == ".P") {
                        cin >> font >> row >> col;
                        getline(cin, text);
                        text = text.substr(2, text.size() - 3);
                        pagina.insert(font, row - 1, col - 1, text);
                } else if (operation == ".L") {
                        cin >> font >> row;
                        getline(cin, text);
                        text = text.substr(2, text.size() - 3);
                        pagina.insert(font, row - 1, 0, text);
                } else if (operation == ".R") {
                        cin >> font >> row;
                        getline(cin, text);
                        text = text.substr(2, text.size() - 3);
                        if (font == "C1") {
                                text = string(60 - text.size(), ' ') + text;
                        } else if (font == "C5") {
                                if (text.size() > 10) {
                                        text = text.substr(text.size() - 10);
                                } else if (text.size() < 10) {
                                        text = string(10 - text.size(), ' ') + text;
                                }
                        }
                        pagina.insert(font, row - 1, 0, text);
                } else if (operation == ".C") {
                        cin >> font >> row;
                        getline(cin, text);
                        text = text.substr(2, text.size() - 3);
                        if (font == "C1") {
                                col = ceil((60 - text.size()) / 2.0);
                        } else if (font == "C5") {
                                col = ceil((60 - ((int) text.size() * 6)) / 2.0);
                        }
                        pagina.insert(font, row - 1, col, text);
                } else if (operation == ".EOP") {
                        pagina.print();
                        cout << '\n';
                        pagina.reset();
                }
        }
        
        return 0;
}
