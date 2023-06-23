#include <bits/stdc++.h>

using namespace std;

bool check(string p1, string p2, string c) {
        if ((c[0] == p1[0] || c[0] == p1[1]) && (c[1] == p2[0] || c[1] == p2[1])) {
                if (c[2] == '-') {
                        return true;
                } else if (c[2] == '+' && (p1[2] == '+' || p2[2] == '+')) {
                        return true;
                }
        }
        if ((c[0] == p2[0] || c[0] == p2[1]) && (c[1] == p1[0] || c[1] == p1[1])) {
                if (c[2] == '-') {
                        return true;
                } else if (c[2] == '+' && (p1[2] == '+' || p2[2] == '+')) {
                        return true;
                }
        }
        return false;
}

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        vector<string> blood_types = { 
                "O-",
                "O+",
                "AB-",
                "AB+",
                "B-",
                "B+",
                "A-",
                "A+",
        };
        
        map<string, vector<string>> alleles = {
                { "O-", { "OO-" } },
                { "O+", { "OO+" } },
                { "AB-", { "AB-" } },
                { "AB+", { "AB+" } },
                { "B-", { "BB-", "BO-" } },
                { "B+", { "BB+", "BO+" } },
                { "A-", { "AA-", "AO-" } },
                { "A+", { "AA+", "AO+" } },
        };

        string p1, p2, c;
        int case_n = 0;

        while (cin >> p1 >> p2 >> c && (p1 + p2 + c != "END")) {
                set<string> sol;
                bool printed = false;
                case_n++;

                cout << "Case " << case_n << ": ";

                if (p1 == "?") {
                        for (size_t i = 0; i < blood_types.size(); i++) {
                                p1 = blood_types[i];
                                for (size_t j = 0; j < alleles[p1].size(); j++) {
                                        for (size_t k = 0; k < alleles[p2].size(); k++) {
                                                for (size_t l = 0; l < alleles[c].size(); l++) {
                                                        if (check(alleles[p1][j], alleles[p2][k], alleles[c][l])) {
                                                                sol.insert(p1);
                                                        }
                                                }
                                        }
                                }
                        }
                        if (sol.size() == 0) {
                                cout << "IMPOSSIBLE ";
                        } else {
                                if (sol.size() > 1) {
                                        cout << "{";
                                }
                                for (size_t i = 0; i < blood_types.size(); i++) {
                                        if (sol.find(blood_types[i]) != sol.end()) {
                                                if (printed) {
                                                        cout << ", ";
                                                }
                                                cout << blood_types[i];
                                                printed = true;
                                        }
                                }
                                if (sol.size() > 1) {
                                        cout << "} ";
                                }
                        }
                        cout << p2 << " " << c << '\n';
                } else if (p2 == "?") {
                        for (size_t i = 0; i < blood_types.size(); i++) {
                                p2 = blood_types[i];
                                for (size_t j = 0; j < alleles[p1].size(); j++) {
                                        for (size_t k = 0; k < alleles[p2].size(); k++) {
                                                for (size_t l = 0; l < alleles[c].size(); l++) {
                                                        if (check(alleles[p1][j], alleles[p2][k], alleles[c][l])) {
                                                                sol.insert(p2);
                                                        }
                                                }
                                        }
                                }
                        }
                        cout << p1;
                        if (sol.size() == 0) {
                                cout << " IMPOSSIBLE ";
                        } else {
                                cout << " ";
                                if (sol.size() > 1) {
                                        cout << "{";
                                }
                                for (size_t i = 0; i < blood_types.size(); i++) {
                                        if (sol.find(blood_types[i]) != sol.end()) {
                                                if (printed) {
                                                        cout << ", ";
                                                }
                                                cout << blood_types[i];
                                                printed = true;
                                        }
                                }
                                if (sol.size() > 1) {
                                        cout << "} ";
                                }
                        }
                        cout << c << '\n';
                } else if (c == "?") {
                        for (size_t i = 0; i < blood_types.size(); i++) {
                                c = blood_types[i];
                                for (size_t j = 0; j < alleles[p1].size(); j++) {
                                        for (size_t k = 0; k < alleles[p2].size(); k++) {
                                                for (size_t l = 0; l < alleles[c].size(); l++) {
                                                        if (check(alleles[p1][j], alleles[p2][k], alleles[c][l])) {
                                                                sol.insert(c);
                                                        }
                                                }
                                        }
                                }
                        }
                        cout << p1 << " " << p2;
                        if (sol.size() == 0) {
                                cout << " IMPOSSIBLE\n";
                        } else {
                                cout << " ";
                                if (sol.size() > 1) {
                                        cout << "{";
                                }
                                for (size_t i = 0; i < blood_types.size(); i++) {
                                        if (sol.find(blood_types[i]) != sol.end()) {
                                                if (printed) {
                                                        cout << ", ";
                                                }
                                                cout << blood_types[i];
                                                printed = true;
                                        }
                                }
                                if (sol.size() > 1) {
                                        cout << "}";
                                }
                                cout << "\n";
                        }
                }
        }
        
        return 0;
}
