/*
idea : just imagine you have both right and left sides both of them must be equal k,k-1,k-2,....k-2,k-1,k
in case if number of nodes is even k,k-1,k-2,..,k-2,k-1,k
in case it is odd k,k-1,k-2,k-3,k-2,k-1,k
Special cases what if nodes could be branched over each other
then after removing left and right from the input the remained elements all of them must be greater than ((mx+1)/2)+1
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define YY cout<<"YES\n"
#define NN cout<<"NO\n"
#define yy cout<<"Yes\n"
#define nn cout<<"No\n"
#ifdef leowang
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
int a[maxn];
multiset<int> st;
int main(){
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin >> a[i];
	int mx = *max_element(a,a+n);
	REP(i,n) st.insert(a[i]);
	REP(i,mx+1){
		int cur = max(i,mx-i);
		if(!st.count(cur)){
			cout<<"Impossible\n";
			return 0;
		}
		st.erase(st.lower_bound(cur));
	}
	for(int i:st){
		if(i<(mx+1)/2+1){
			cout<<"Impossible\n";
			return 0;
		}
	}
	cout<<"Possible\n";
	return 0;
}
