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
        map<string, vector<int>> zodiacs = {
                { "aquarius" , { 1, 21, 2, 19 } },
                { "pisces" , { 2, 20, 3, 20 } },
                { "aries" , { 3, 21, 4, 20 } },
                { "taurus" , { 4, 21, 5, 21 } },
                { "gemini" , { 5, 22, 6, 21 } },
                { "cancer" , { 6, 22, 7, 22 } },
                { "leo" , { 7, 23, 8, 21 } },
                { "virgo" , { 8, 22, 9, 23 } },
                { "libra" , { 9, 24, 10, 23 } },
                { "scorpio" , { 10, 24, 11, 22 } },
                { "sagittarius" , { 11, 23, 12, 22 } },
                { "capricorn" , { 12, 23, 1, 20 } },
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

        string zodiac() {
                int di, df, mi, mf;
                for (map<string, vector<int>>::iterator it = zodiacs.begin(); it != zodiacs.end(); it++) {
                        di = it->second[1];
                        mi = it->second[0];
                        df = it->second[3];
                        mf = it->second[2];

                        if ((month == mi && day >= di) || (month == mf && day <= df)) {
                                return it->first;
                        }
                }
                return "";
        }
};

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N, dd, mm, yy;
        string query;

        cin >> N;

        for (int _ = 0; _ < N; _++) {
                cin >> query;
                dd = stoi(query.substr(2, 2));
                mm = stoi(query.substr(0, 2));
                yy = stoi(query.substr(4));

                Date date(dd, mm, yy);
                date.add_days(280);

                cout << setfill('0') << (_ + 1) << " " << setw(2) << date.month << "/"  << setw(2) << date.day << "/" << date.year << " " << date.zodiac() << '\n';
        }
        
        return 0;
}
