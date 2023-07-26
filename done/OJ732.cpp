#include <bits/stdc++.h>

using namespace std;

void PrintActions(string &actions) {
    cout << actions[0];
    for (size_t i = 1; i < actions.size(); ++i) {
        cout << ' ' << actions[i];
    }
    cout << '\n';
}

void GeneratePerms(string &source, string &target, int source_index,
                   int target_index, stack<char> &word_stack, string actions) {
    if (source_index == source.size() && word_stack.empty()) {
        PrintActions(actions);
        return;
    }
    if (source_index < source.size()) {
        word_stack.push(source[source_index]);
        GeneratePerms(source, target, source_index + 1, target_index,
                      word_stack, actions + 'i');
        word_stack.pop();
    }
    if (!word_stack.empty() && word_stack.top() == target[target_index]) {
        char tmp = word_stack.top();
        word_stack.pop();
        GeneratePerms(source, target, source_index, target_index + 1,
                      word_stack, actions + 'o');
        word_stack.push(tmp);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string source, target;

    while (cin >> source >> target) {
        string test_1, test_2;

        test_1 = source;
        test_2 = target;

        sort(test_1.begin(), test_1.end());
        sort(test_2.begin(), test_2.end());

        cout << "[\n";

        if (test_1 == test_2) {
            stack<char> word_stack;
            GeneratePerms(source, target, 0, 0, word_stack, "");
        }

        cout << "]\n";
    }

    return 0;
}
