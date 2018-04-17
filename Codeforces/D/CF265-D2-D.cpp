


#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <unordered_set>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a,val)            memset( a,  val,  sizeof(a) )
#define pb                    push_back
#define all(x)                (x).begin(), (x).end()
#define sz(a)                 int((a).size())
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define nl                    "\n"
const int maxn = 1e5+5;
int ar[maxn];
int factors[maxn];
int sp[maxn];
void pre()
{
	for(int i = 2; i < maxn; i++)
		if(!sp[i])
		{
			sp[i] = i;
			for(long long j = 1LL*i*i; j < maxn; j+=i)
			{
				sp[j] = i;
			}
		}
}
unordered_set<int> factorize(int n)
{
	unordered_set<int> ret;
	while(n != 1)
	{
		ret.insert(sp[n]);
		if(sp[n] == 0)
			break;
		n/=sp[n];
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	pre();
	for(int i = 0; i < n; ++i)
		scanf("%d", &ar[i]);
	for(int i = n-1; i >= 0; i--)
	{
		unordered_set<int> facs = factorize(ar[i]);
		int curans = -1;
		for(int x : facs)
		{
			curans = max(curans, factors[x]+1);
		}
		for(int x : facs)
			factors[x] = curans;
	}
	int ans = 0;
	for(int i = 0 ; i < maxn; i++)
		ans = max(ans, factors[i]);
	cout<<max(ans, 1)<<nl;
}
