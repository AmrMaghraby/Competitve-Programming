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
#include <fstream>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
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

using namespace std;

bool DP[105][10][2];
string s;
string res;

bool can(int ind, int m, bool t)
{
  if(DP[ind][m][t]) return false;
  if(ind == s.size()) return (m == 0 && t);
  DP[ind][m][t] = true;
  if(can(ind + 1, m, t)) return true;
  int nxt = m * 10 + s[ind] - '0';
  nxt%=8;
  if(can(ind + 1, nxt, 1))
  {
    res+=s[ind];
    return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> s;
  if(can(0, 0, 0))
  {
    cout << "YES\n";
    reverse(res.begin(), res.end());
    cout << res;
  }
  else cout << "NO";
  return 0;
}
