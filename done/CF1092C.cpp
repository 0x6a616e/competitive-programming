// https://codeforces.com/problemset/problem/1092/C

#include <bits/stdc++.h>

using namespace std;

bool isPrefix(string &full, string &pre) {
    for (int i = 0; i < (int)pre.size(); ++i)
        if (full[i] != pre[i]) return false;
    return true;
}

bool isSuffix(string &full, string &suf) {
    int offset = (int)(full.size() - suf.size());
    for (int i = 0; i < (int)suf.size(); ++i)
        if (full[i + offset] != suf[i]) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> input(2 * n - 2);
    vector<string> input_sorted;
    unordered_map<string, string> mapeador;
    unordered_map<string, int> mapeador_indice;
    for (int i = 0; i < 2 * n - 2; ++i) cin >> input[i];
    input_sorted = input;
    sort(input_sorted.begin(), input_sorted.end(), [](string &a, string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() > b.size();
    });
    string pre = input_sorted[0];
    string suf = input_sorted[1];
    bool done = false;
    for (int i = 0; i < (int)input_sorted.size(); i += 2) {
        if (isPrefix(pre, input_sorted[i]) &&
            isSuffix(suf, input_sorted[i + 1])) {
            mapeador[input_sorted[i]] += 'P';
            mapeador[input_sorted[i + 1]] += 'S';
        } else if (isPrefix(pre, input_sorted[i + 1]) &&
                   isSuffix(suf, input_sorted[i])) {
            mapeador[input_sorted[i]] += 'S';
            mapeador[input_sorted[i + 1]] += 'P';
        } else {
            break;
        }
        if (i == (int)(input_sorted.size() - 2)) done = true;
    }
    pre = input_sorted[1];
    suf = input_sorted[0];
    if (!done) {
        mapeador.clear();
        for (int i = 0; i < (int)input_sorted.size(); i += 2) {
            if (isPrefix(pre, input_sorted[i]) &&
                isSuffix(suf, input_sorted[i + 1])) {
                mapeador[input_sorted[i]] = +'P';
                mapeador[input_sorted[i + 1]] += 'S';
            } else if (isPrefix(pre, input_sorted[i + 1]) &&
                       isSuffix(suf, input_sorted[i])) {
                mapeador[input_sorted[i + 1]] += 'P';
                mapeador[input_sorted[i]] += 'S';
            } else {
                break;
            }
            if (i == (int)(input_sorted.size() - 2)) done = true;
        }
    }
    for (string &s : input) cout << mapeador[s][mapeador_indice[s]++];

    cout << '\n';
    return 0;
}
