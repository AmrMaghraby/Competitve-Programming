#include <iostream>
#include <cstdio>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include<cassert>
#include <set>
#include<bitset>
#include<sstream>
#include<iomanip>
#include<numeric>
#include <climits>
#include<string>
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define eps 1e-9
#define fi first
#define se second
#define endl '\n'
#define io  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen ("input.txt", "r", stdin),freopen ("output.txt", "w", stdout);
#define filein freopen ("in.txt", "r", stdin);
#define all(v) ((v).begin()), ((v).end())
#define mid ((st + en) >> 1)
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<vector<long long> > matrix;
typedef pair<pii, int> piii;
const int N = (int)3e5 + 5;
int a[N], b[N], posA[N], posB[N], A, B;
int main(){
	io;
	memset(posA, 64, sizeof a);
	memset(posB, 64, sizeof b);
	int n, lst;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> lst;
		if(lst == 1){
			A++;
			posA[A] = i;
		}else{
			B++;
			posB[B] = i;
		}
		a[i] = A;
		b[i] = B;
	}
	vector<pii> ans;
	for(int t = 1; t <= n; t++){
		int curPos = 0, wonA = 0, wonB = 0;
		while(curPos < n){
			int toA = posA[a[curPos] + t];
			int toB = posB[b[curPos] + t];
			if(toA < toB){
				wonA++;
				curPos = toA;
			}else{
				wonB++;
				curPos = toB;
			}
		}
		if(curPos == n){
			if(lst == 1 && wonA > wonB)
				ans.pb(mp(wonA, t));
			if(lst == 2 && wonB > wonA)
				ans.pb(mp(wonB, t));
		}
	}
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	for(auto x : ans)
		printf("%d %d\n", x.fi, x.se);
	return 0;
}
