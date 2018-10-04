// UVa 10944 - Nuts for nuts..
// DP with bitmask

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <string.h>
using namespace std;

struct pos {
	int i, j;
};

int n, oo, T[65536][15];
vector<pos> nuts;

int dist(int a, int b) {
	return int(max(abs(nuts[a].i - nuts[b].i), abs(nuts[a].j - nuts[b].j)));
}

int comb(int current_mask, int fin) {
	if (T[current_mask][fin] == oo) {
		int subsol = oo;
		if (current_mask == ((1 << n) - 1))
			subsol = dist(fin, n);
		else {
			for (int i = 0; i < n; i++) {
				if (((current_mask >> i) & 1) == 0) {
					int next_mask = current_mask | (1 << i);
					int cand = dist(fin, i) + comb(next_mask, i);
					if (cand < subsol)
						subsol = cand;
				}
			}
		}
		T[current_mask][fin] = subsol;
	}
	return T[current_mask][fin];
}

int main() {
	int r, c;
	while (cin >> r >> c) {
		pos larry;
		nuts.clear();
		for (int i = 0; i < r; i++) {
			string a;
			cin >> a;
			for (int j = 0; j < c; j++) {
				if (a[j] == '#')
					nuts.push_back( { i, j });
				else if (a[j] == 'L')
					larry = {i,j};
				}
			}
		n = nuts.size();
		nuts.push_back(larry);

		memset(T, 127, sizeof(T));
		oo = T[0][0];
		int sol = oo;

		if (n == 0)
			sol = 0;
		else {
			for (int i = 0; i < n; i++)
				if (comb(1 << i, i) + dist(n, i) < sol)
					sol = comb(1 << i, i) + dist(n, i);
		}
		cout << sol << endl;
	}
	return 0;
}
