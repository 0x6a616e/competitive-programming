#include <bits/stdc++.h>

using namespace std;

vector<string> rotate_s(vector<string> &square, int n) {
	vector<string> square2(n);
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			square2[i] += square[j][i];
		}
	}
	return square2;
}

int count_appearences(vector<string> &bigS, int N, vector<string> &smallS, int n) {
	int c = 0;
	bool posible;
	for (int y = 0; y < N - n + 1; ++y) {
		for (int x = 0; x < N - n + 1; ++x) {
			posible = true;
			for (int i = 0; i < n && posible; ++i) {
				for (int j = 0; j < n && posible; ++j) {
					if (bigS[y + i][x + j] != smallS[i][j]) {
						posible = false;
					}
				}
			}
			if (posible) {
				++c;
			}
		}
	}
	return c;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int N, n;

	while(cin >> N >> n && N && n) {
		vector<string> bigS(N);
		vector<string> smallS(n);
		char l;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> l;
				bigS[i] += l;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> l;
				smallS[i] += l;
			}
		}
		for (int i = 0; i < 4; ++i) {
			cout << count_appearences(bigS, N, smallS, n);
			smallS = rotate_s(smallS, n);
			if (i < 3) {
				cout << ' ';
			} else {
				cout << '\n';
			}
		}
	}

	return 0;
}

