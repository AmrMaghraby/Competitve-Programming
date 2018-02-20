#include <iostream>
using namespace std;
long long n, a[200005], dp[200005][2]; bool visited[200005][2];
long long solve(int x, bool d){
	if (x < 1 || x > n) return 0;
	if (visited[x][d]) return dp[x][d];
	visited[x][d] = 1, dp[x][d] = -1;
	long long ans = solve(x + a[x] * (d ? 1 : -1), !d); if (ans != -1) ans += a[x];
	return dp[x][d] = ans;
}
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		a[1] = i;
		visited[1][0] = visited[1][1] = 0;
		cout << solve(1, 1) << endl;
	}
	return 0;
}
