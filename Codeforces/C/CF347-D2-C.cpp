#include <bits/stdc++.h>
using namespace std;

int n, m, a, d, i;

int main() {
	cin >> n;
	for (i = 0; i < n; ++i) {
	    cin >> a;
	    d = __gcd(d, a);
	    m = max(m, a);
	}
	cout << ((m / d - n) % 2 ? "Alice" : "Bob") << endl;
	return 0;
}
