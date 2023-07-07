#include <bits/stdc++.h>

using namespace std;

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
	}

	return 0;
}

