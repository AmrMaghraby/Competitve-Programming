 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 using namespace std;
   int const N = 3e4 + 1;
   int n,k,t,vec[N * 3], ori[N], SegTree[N * 3 * 4];
   long long Query(int ss, int se, int qs, int qe, int si){
    if (qs <= ss && qe >= se) return SegTree[si];
    if (se < qs || ss > qe) return (1ll<<31)-1;
    int mid = ss + (se - ss)/2;
    return Query( ss, mid, qs, qe, 2*si) & Query(mid+1, se, qs, qe, 2*si+1);
   }
   void constructSTUtil( int ss, int se, int si){
    if(ss==se){
        SegTree[si] = vec[ss];
        return ;
    }
    int mid = ss + (se - ss)/2;
    constructSTUtil(ss,mid,si*2);
    constructSTUtil(mid+1,se,si*2+1);
    SegTree[si]=SegTree[2*si] & SegTree[2*si+1];
  }
 int s, e;
  int main(){
   int Tc,n,k;
   cin >> Tc;
   while(Tc--){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
  		scanf("%d", vec + i), vec[i + (n) + (n)] = vec[i + (n)] = vec[i];
  	//constructSTUtil(1,n*3,1);
  	constructSTUtil(1, n*3, 1);
  	int qs,qe;
  	for(int i = n + 1; i <= n + n; ++i) {
  		s = max(1, i - k), e = min(n * 3, i + k);
  		ori[i - n] = Query(1,n*3,s,e,1);;
  	}
  	for(int i = 1; i <= n; ++i)
  		printf("%s%d", i == 1 ? "" : " ", ori[i]);
  	puts("");
   }
   return 0;
  }

  
