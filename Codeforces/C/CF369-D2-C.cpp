#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ford(i,n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i,a,b) for(int i = int(a); i <= int(b); i++)
#define foreach(it,a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;

const int INF = 1000000000;
const li INF64 = li(INF) * li(INF);
const ld EPS = ld(1e-9);
const ld PI = ld(3.1415926535897932384626433832795);

int n;
const int N = 300000 + 300;
int white[N], d[N];       
vector < int > g[N];

inline bool read() {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n - 1)
	{
	 	int x, y, t;

	 	assert(scanf("%d %d %d", &x, &y, &t) == 3);
		x--, y--;

		g[x].pb(y);
		g[y].pb(x);
		
		if (t == 2)
		{
		 	white[x] = 1;
		 	white[y] = 1;
		}
	}

	return true;
}


void go(int v, int prev = -1)
{
	d[v] = white[v];
	forn(i, sz(g[v]))
	{
		int to = g[v][i];

		if (prev == to)
			continue;
		go(to, v);
		d[v] += d[to];
	}	
}
inline void solve() 
{
	go(0);
	vector < int > ans;
  	forn(i, n)
  	{
  		if (white[i] && d[i] == 1)
  		{
  			ans.pb(i + 1);
  		}
  	}

  	printf("%d\n", sz(ans));

  	forn(i, sz(ans))
  	{
  	  	if (i) printf(" ");
  	  	printf("%d", ans[i]);
  	}
}

int main() {
 #ifdef gridnevvvit
 	freopen("input.txt", "rt", stdin);
 	freopen("output.txt", "wt", stdout);
 #endif
  assert(read());
  solve();
   #ifdef gridnevvvit 
 	cerr << "Time == " << clock() << endl;
 #endif
}
