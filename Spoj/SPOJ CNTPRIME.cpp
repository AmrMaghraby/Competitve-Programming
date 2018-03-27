 #include<bits/stdc++.h>
 using namespace std;
 long long s[400001],lazy[400001],Arr[400000];
 bool Primes[10000000];
 int v;
 void Build(int id,int l ,int r){
   if(l==r){
     if(Primes[Arr[l]]) s[id]=1;
     else s[id]=0;
    return ;
   }
   int mid = (l+r)/2;
   Build(id*2,l,mid);
   Build(id*2+1,mid+1,r);
   s[id] = s[2*id] + s[2*id+1];
 }
 void update(int x,int y,int id,int l ,int r){
   if(x > r || x < l || l > r) return ;
   if(x<=l && y>=r){
    s[id]=(l-r+1)*Primes[v];
    lazy[2*id]=(l-r)*Primes[v];
    lazy[2*id+1]=(l-r)*Primes[v];
    return ;
   }
    int mid = (l+r)/2;
    update(x,y,2*id,l,mid);
    update(x,y,2*id+1,mid+1,r);
    s[id]=(s[id*2]+s[id*2+1]);
    return ;
 }
 long long Query(int x,int y,int id ,int l,int r){
  if( x > r || y < l ) return 0LL;
  if(lazy[id]){
    s[id]=lazy[id];
    if(l!=r){
       lazy[2*id]=(l-r)*Primes[v];;
       lazy[2*id+1]=(l-r)*Primes[v];;
    }
    lazy[id]=0;
  }
  if( x<=l && y>=r ) return s[id];
  int mid = (l+r)/2;
  return Query(x,y,2*id,l,mid)+Query(x,y,2*id+1,mid+1,r);
 }
 void Print(int l,int r,int id){
   if(l==r){
     cout<<l<<" "<<r<<" "<<s[id]<<endl;
     return ;
   }
     cout<<l<<" "<<r<<" "<<s[id]<<endl;
   int mid = (l+r)/2;
   Print(l,mid,id*2);
   Print(mid+1,r,id*2+1);
 }
 int main(){
 int n ,m,tc;
 for(int i=2;i<1e7;i++) Primes[i]=1;
 for(long long i=2;i<1e7;i++)
  if(Primes[i])
   for(long long j=i+i;j<1e7;j+=i)
       Primes[j]=0;
  scanf("%d",&tc);
  int id=1;
  while(tc--){
     memset(s,0,sizeof s);
     memset(Arr,0,sizeof Arr);
     memset(lazy,0,sizeof lazy);
     printf("Case %d:\n",id++);
     scanf("%d %d",&n,&m);
     for(int i=1;i<=n;i++)
       scanf("%d",&Arr[i]);
     Build(1,1,n);
     for(int i=0;i<m;i++){
        int q,a,b;
        scanf("%d %d %d",&q,&a,&b);
        if(q==0){
            scanf("%d",&v);
            update(a,b,1,1,n);
        }else {
          ///  Print(1,n,1);
            printf("%I64d\n",Query(a,b,1,1,n));
          ///  Print(1,n,1);
        }
     }
  }
 }
