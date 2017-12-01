#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)


typedef long long         ll;
const ll OO = 1e8;

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

int a[1000001] ;
int main ()
{
    int n ;
    int l ;
    cin>>n ; ll ans1 =0 , ans2 =0  ;
    vector <int> a(n) ;
    for(int i=0;i<n;i++){
        cin>>a[i] ;
    }
    sort(all(a)) ;
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]||a[i]+1==a[i+1])
			if(ans2) { ans1+=(ans2*a[i]) ; ans2=0 ; i-=1 ; }
			else{ans2=a[i] ; i-=1 ;}
    }
    cout<<ans1 ;
    return 0 ;

}
