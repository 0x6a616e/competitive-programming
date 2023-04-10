#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int L;
        string state, decision;

        while (cin >> L && L != 0) {
                state = "+x";
                for (int i = 0; i < L - 1; i++) {
                        cin >> decision;
                        if (decision == "+y") {
                                if (state == "+x") {
                                        state = "+y";
                                } else if (state == "-x") {
                                        state = "-y";
                                } else if (state == "+y") {
                                        state = "-x";
                                } else if (state == "-y") {
                                        state = "+x";
                                }
                        } else if (decision == "-y") {
                                if (state == "+x") {
                                        state = "-y";
                                } else if (state == "-x") {
                                        state = "+y";
                                } else if (state == "+y") {
                                        state = "+x";
                                } else if (state == "-y") {
                                        state = "-x";
                                }
                        } else if (decision == "+z") {
                                if (state == "+x") {
                                        state = "+z";
                                } else if (state == "-x") {
                                        state = "-z";
                                } else if (state == "+z") {
                                        state = "-x";
                                } else if (state == "-z") {
                                        state = "+x";
                                }
                        } else if (decision == "-z") {
                                if (state == "+x") {
                                        state = "-z";
                                } else if (state == "-x") {
                                        state = "+z";
                                } else if (state == "+z") {
                                        state = "+x";
                                } else if (state == "-z") {
                                        state = "-x";
                                }
                        }
                }
                cout << state << '\n';
        }

        return 0;
}
