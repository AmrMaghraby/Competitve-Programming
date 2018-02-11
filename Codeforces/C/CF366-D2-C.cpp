#include <bits/stdc++.h>
using namespace std;

const int n_ = 101, MAX = 200000;
int n, k;
int t[n_], c[n_], memo[n_][MAX];
int off = 100000;
int dp (int idx, int diff) {
	if (idx == n) return diff == off ? 0 : -1e7;

	int &ret = memo[idx][diff];
	if (ret != -1) return ret;
	diff -= off;

	return ret = max(dp(idx + 1, diff + off),
			t[idx] + dp(idx + 1, diff + t[idx] - c[idx] * k + off));
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	memset (memo, -1, sizeof memo);

	printf("%d\n", dp(0, off) == 0 ? -1 : dp(0, off));
	return 0;
}
