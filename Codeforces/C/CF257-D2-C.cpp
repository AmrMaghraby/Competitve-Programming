#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double angles[100100], PI = acos(-1.0);

int main() {
	int n, x, y, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i)
		scanf("%d %d", &x, &y),
		angles[i] = atan2(y, x) * 180.0 / PI;

	sort(angles, angles + n);

	double ans = angles[n - 1] - angles[0];

	for (i = 1; i < n; ++i)
		ans = min(ans, 360.0 - (angles[i] - angles[i - 1]));

	printf("%0.12f", ans);
	return 0;
}
