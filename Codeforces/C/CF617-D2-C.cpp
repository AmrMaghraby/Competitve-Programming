#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
ll square(int x) {
    return x * (ll) x;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector< pair<ll, ll> > dist(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dist[i].first = square(x - x1) + square(y - y1);
        dist[i].second = square(x - x2) + square(y - y2);
    }
    dist.push_back({0, 0});
 
    ll result = 8e18;
    for (auto i: dist) {
        ll r1 = i.first;
        ll r2 = 0;
        for (auto j: dist) {
            if (j.first > r1) {
                r2 = max(r2, j.second);
            }
        }
        result = min(result, r1 + r2);
    }
 
    cout << result << '\n';
}
