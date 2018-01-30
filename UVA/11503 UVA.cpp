
///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int n,m,h[50005],pa[50005],id;
 void Make_SET(int n){
  for(int i=1;i<=n;i++){
        pa[i]=i;
        h[i]=1;
  }
 }
 int find(int x){
  if(x==pa[x])return x;
   return pa[x]=find(pa[x]);
 }
 void Union(int x,int y){
  if(x==y)return;
  if(h[x]>=h[y]){
        h[x]++;
        pa[y]=x;
  } else {
    h[y]++;
    pa[x]=y;
  }
}
 int main(){
 while(true){
     cin >> n;
     memset(pa,0,sizeof pa);
     memset(h,0,sizeof h);
     Make_SET(n);
     int m;
     cin >> m;

     if(!n&&!m) break;
     int SC = n;
     long long int S=1;
     for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      if(find(a)!=find(b)){
             Union(find(a),find(b));
             SC--;
      }
     }
     id++;
     cout<<"Case "<<id<<": "<<SC<<endl;
    }
 }

