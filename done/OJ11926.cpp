#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int single_tasks, repeating_tasks;

    while (cin >> single_tasks >> repeating_tasks &&
           (single_tasks || repeating_tasks)) {
        bool conflict_found = false;
        vector<bool> time_slots(1000000, false);
        int start_time, end_time, repetition_time;

        for (int i = 0; i < single_tasks; ++i) {
            cin >> start_time >> end_time;
            for (int t = start_time; t < end_time && !conflict_found; ++t) {
                if (time_slots[t]) {
                    conflict_found = true;
                } else {
                    time_slots[t] = true;
                }
            }
        }

        for (int i = 0; i < repeating_tasks; ++i) {
            cin >> start_time >> end_time >> repetition_time;
            for (int j = 0; start_time + repetition_time * j <= 1000000; ++j) {
                for (int k = start_time + repetition_time * j;
                     k < end_time + repetition_time * j && k < 1000000; ++k) {
                    if (time_slots[k]) {
                        conflict_found = true;
                    } else {
                        time_slots[k] = true;
                    }
                }
            }
        }

        if (conflict_found) {
            cout << "CONFLICT\n";
        } else {
            cout << "NO CONFLICT\n";
        }
    }

    return 0;
}
