#include <bits/stdc++.h>

using namespace std;

struct Date {
        int day, month, year;
        vector<vector<int>> calendar = {
                { 0, 0 },
                { 31, 31 },
                { 28, 29 },
                { 31, 31 },
                { 30, 30 },
                { 31, 31 },
                { 30, 30 },
                { 31, 31 },
                { 31, 31 },
                { 30, 30 },
                { 31, 31 },
                { 30, 30 },
                { 31, 31 },
        };

        Date(int dd, int mm, int yy) {
                day = dd;
                month = mm;
                year = yy;

                add_days(0);
        }

        void add_days(int days_to_add) {
                day += days_to_add;
                int leap = is_leap();

                while (day > calendar[month][leap]) {
                        day -= calendar[month][leap];
                        month++;
                        if (month > 12) {
                                month = 1;
                                year++;
                                leap = is_leap();
                        }
                }
        }

        int is_leap() {
                if (year % 400 == 0) {
                        return 1;
                }
                if (year % 4 == 0 && year % 100 != 0) {
                        return 1;
                }
                return 0;
        }
};

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int days_to_add, day, month, year;

        while (cin >> days_to_add >> day >> month >> year && (days_to_add || day || month || year)) {
                Date date(day, month, year);
                date.add_days(days_to_add);
                cout << date.day << " " << date.month << " " << date.year << '\n';
        }

        return 0;
}
