#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 1e6 + 100;
int a[maxn], n, l[maxn], r[maxn], ans[maxn];
stack<int> s;
int main(){
	scanf("%d", &n);
	For(i,0,n)
		scanf("%d", a + i);
	fill(l, l + maxn, -1);
	fill(r, r + maxn, n);
	For(i,0,n){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty())
			l[i] = s.top();
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	rof(i,n-1,-1){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty())
			r[i] = s.top();
		s.push(i);
	}
	For(i,0,n){
		int len = r[i] - l[i] - 1;
		smax(ans[len], a[i]);
	}
	rof(i,n,-1)
		smax(ans[i], ans[i+1]);
	For(i,1,n+1)
		printf("%d ", ans[i]);
	cout << endl;
	return 0;
}
