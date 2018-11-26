#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define debug(a) cerr << #a << ": " << (a) << endl
#define fast std::ios_base::sync_with_stdio(false);
#define ll long long
#define lp(i,n) for(int i=0;i<(int)n;i++)
#define endl "\n"
#define bitcnt(m) __builtin_popcountll(m)
#define neg(DP) memset(DP,-1,sizeof(DP));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define FOR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
int n,a,b;
int arr[1000000+5];
int prime;
vector<int> primes;
set<int> S;
ll DP[1000000+5][5][2];
#define add push_back

ll solve(int idx,int flag,int took)
{


	if(idx == n)
	{
		if(took == 0 && flag == 1) return 1LL<<52;
		return 0;
	}

	if(DP[idx][flag][took] != -1) return DP[idx][flag][took];
	int m = arr[idx] % prime;
	int newFlag = took | (idx == 0 ? 1 : 0);
	ll ret = 1LL<<52;

	if(flag == 0)
	{
		if( (m==0) || (m-1)==0 || (m+1)==prime )
		{
			ret = solve(idx+1,flag,newFlag) + (m == 0 ? 0 : a);
		}

		ret = min(ret,solve(idx+1,1,took)+b);
	}
	if(flag == 1)
	{
		ret = min(solve(idx,2,took),solve(idx+1,flag,took)+b);
	}

	if(flag == 2)
	{
		if( (m==0) || (m-1)==0 || (m+1)==prime )
		{
			ret = solve(idx+1,flag,newFlag) + (m == 0 ? 0 : a);
		}
		else return 1LL << 52;
	}



	return DP[idx][flag][took] = ret;
}
int main()
{
	fast

	cin >> n >> b >> a;
	lp(i,n) cin >> arr[i];
	vector<int> nums;

	nums.add(arr[0]);
	nums.add(arr[0]+1);
	nums.add(arr[0]-1);
	if(n > 1)
	{
		nums.add(arr[n-1]);
		nums.add(arr[n-1]+1);
		nums.add(arr[n-1]-1);
	}


	rep(k,nums)
	{
		int num = nums[k];
		for(int i = 2 ; i * i <= num ; i++ )
		{
			if(num % i == 0)
			{
				while(num % i == 0)
				{
					num /= i;
				}

				if(S.find(i) == S.end())
				{
					primes.push_back(i);
					S.insert(i);
				}
			}
		}
		if(num != 1){
			if(S.find(num) == S.end())
			{
				primes.push_back(num);
				S.insert(num);
			}

		}
	}


	ll ans = 1LL << 52;
	rep(k,primes)
	{
		prime = primes[k];
		neg(DP);
		ans = min(ans,solve(0,0,0));

	}
	cout << ans;
}
