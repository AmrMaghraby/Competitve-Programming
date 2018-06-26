#include<bits/stdc++.h>
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
///---------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;

///  Digit     0123456789012345678 ///
#define MX     5005
#define inf    2000000010
#define eps    1e-9
///===============================///
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)


vector<int>G[MX+2];
int fn,n,ds,dis[MX];

void Dfs(int u,int p,int l) {
    dis[u]=Max(dis[u],l);
    if(l>ds) {
        ds=l;
        fn=u;
    }
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[u][i];
        if( v==p )continue;
        Dfs( v,u,l+1 );
    }
}

int main() {
    int tc,cs=1,i,j,k,x;
    while(S(n)==1) {
        for(i=1; i<=n; i++) {
            G[i].clear();
            S(k);
            for(j=1; j<=k; j++) {
                S(x);
                G[i].pb(x);
            }
        }
        CLR(dis);
        ds=0;
        Dfs(1,-1,1);
        ds=0;
        Dfs(fn,-1,1);
        ds=0;
        Dfs(fn,-1,1);
        int mn=inf,mx=-inf;
        for(i=1; i<=n; i++) {
            mx=Max( mx,dis[i] );
            mn=Min( mn,dis[i] );
        }
        printf("Best Roots  :");
        for(i=1; i<=n; i++) {
            if(dis[i]==mn) printf(" %d",i);
        }
        puts("");
        printf("Worst Roots :");
        for(i=1; i<=n; i++) {
            if(dis[i]==mx) printf(" %d",i);
        }
        puts("");
    }
    return 0;
}
