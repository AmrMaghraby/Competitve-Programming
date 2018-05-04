#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <set>
#include <numeric>
#include <cassert>
#include <ctime>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

vector<int> g[205];

bool v[205];
int v2[205];
int res, n, ch, maxi;

void dfs(int node, int c, int parent = -1, int l = 0)
{
  if(v2[node] == c || v[node]) return;
  if(l > maxi)
    maxi = l, ch = node;
  v2[node] = c;
  for(int i=0;i<g[node].size();i++)
  {
    if(g[node][i] == parent) continue;
    dfs(g[node][i], c, node, l + 1);
  }
}

void solve(int node, int parent = -1, int l = 0)
{
  v[node] = true;
  if(l)
  {
    for(int i=1;i<=n;i++)
      v2[i] = 0;
    for(int i=1;i<=n;i++)
    {
      if(v[i] || v2[i]) continue;
      maxi = -1;
      dfs(i, 1);
      maxi = -1;
      dfs(ch, 2);
      res = max(res, l * maxi);
    }
  }
  for(int i=0;i<g[node].size();i++)
  {
    if(g[node][i] == parent) continue;
    solve(g[node][i], node, l + 1);
  }
  v[node] = false;
}

int main()
{
  //freopen("approximation.in", "r", stdin);
  //freopen("approximation.out", "w", stdout);
  int x, y;
  scanf("%d", &n);
  for(int i=1;i<n;i++)
  {
    scanf("%d %d" ,&x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  for(int i=1;i<=n;i++)
    solve(i);
  printf("%d", res);
  return 0;
}
