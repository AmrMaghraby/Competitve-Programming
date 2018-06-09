#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include<bitset>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
const int maxn=100100;
int l[maxn],r[maxn];

void link(int a,int b){
    r[a]=b,l[b]=a;
}

int main(){
    int n,m,cas=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        int flag=0;
        int x,y,op;
        for(int i=1;i<=n;i++)
            r[i]=i+1,l[i]=i-1;
        r[0]=1,l[0]=-1;r[n+1]=-1,l[n+1]=n;
        for(int i=1;i<=m;i++){
            scanf("%d",&op);
            if(op==4){
                flag^=1;
                continue;
            }
            if(flag&&op<=2)
                op=3-op;
            scanf("%d%d",&x,&y);
            if(op==1&&l[y]==x)  //这两步不能缺少
                continue;
            if(op==2&&r[y]==x)
                continue;
            int lx=l[x],rx=r[x],ly=l[y],ry=r[y];
            if(op==1)  //将x插入到y的前面
                link(lx,rx),link(ly,x),link(x,y);
            else if(op==2) //将x插入到y的后面
                link(lx,rx),link(y,x),link(x,ry);
            else{
                if(rx==y)
                    link(lx,rx),link(y,x),link(x,ry);
                else if(l[x]==y)
                    link(lx,rx),link(ly,x),link(x,y);
                else
                    link(lx,y),link(y,rx),link(ly,x),link(x,ry);
            }
        }
        int k=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            k=r[k];
            if(i&1)
                ans+=k;
        }
        if(flag)
            ans=(long long)n*(n+1)/2-ans;
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
