#include <cstddef>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void InsertLetter(vector<char> &stacks, char letter) {
    int diff = -1;
    for (size_t i = 0; i < stacks.size(); ++i) {
        if (letter <= stacks[i]) {
            if (diff == -1 || stacks[i] - letter < stacks[diff] - letter) {
                diff = i;
            }
        }
    }
    if (diff != -1) {
        stacks[diff] = letter;
    } else {
        stacks.push_back(letter);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string case_string;
    int case_number = 0;

    while (cin >> case_string && case_string != "end") {
        vector<char> stacks;
        set<char> letters;

        for (size_t i = 0; i < case_string.size(); ++i) {
            letters.insert(case_string[i]);
            if (i == 0) {
                stacks.push_back(case_string[i]);
            } else {
                InsertLetter(stacks, case_string[i]);
            }
        }

        cout << "Case " << ++case_number << ": "
             << min((int)letters.size(), (int)stacks.size()) << '\n';
    }

    return 0;
}
