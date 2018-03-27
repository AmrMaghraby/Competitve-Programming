 #include<bits/stdc++.h>
 using namespace std;
 long long s[400001],lazy[400001],Arr[400000];
 vector<int> v;
 void Build(int id,int l ,int r){
   if(l==r){
      s[id]=Arr[l];
    return ;
   }
   int mid = (l+r)/2;
   Build(id*2,l,mid);
   Build(id*2+1,mid+1,r);
   s[id] = min(s[2*id] , s[2*id+1]);
   return ;
 }
 void update(int x,int y,int id,int l ,int r){
   if(x > r || y < l) return ;
   if(x<=l && y>=r){
    lazy[id]+=v[2];
    s[id]+=lazy[id];
    if(l!=r){
     lazy[2*id]+=lazy[id];
     lazy[2*id+1]+=lazy[id];
    }
    lazy[id]=0;
    return ;
   }
    int mid = (l+r)/2;
    update(x,y,2*id,l,mid);
    update(x,y,2*id+1,mid+1,r);
    s[id]=min(s[id*2],s[id*2+1]);
    return ;
 }
 long long Query(int x,int y,int id ,int l,int r){
  if( x > r || y < l ) return 1e9;
  if(lazy[id]){
    s[id]+=lazy[id];
    if(l!=r){
     lazy[2*id]+=lazy[id];
     lazy[2*id+1]+=lazy[id];
    }
    lazy[id]=0;
  }
  if( x<=l && y>=r ) return s[id];
  int mid = (l+r)/2;
  return min(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid+1,r));
 }
 void Print(int l,int r,int id){
   if(l==r){
    cout<<l<<" "<<r<<" "<<Arr[l]<<" "<<s[id]<<" "<<id<<endl;
    return ;
   }
   int mid=(l+r)/2;
   Print(l,mid,id*2);
   Print(mid+1,r,id*2+1);
    cout<<l<<" "<<r<<" "<<Arr[l]<<" "<<s[id]<<" "<<id<<endl;
   return ;
 }
 int main(){
     int n ,m,tc;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&Arr[i]);
     Build(1,1,n);
     cin>>m;
     cin.ignore();
     for(int i=0;i<m;i++){
        string str;
        getline(cin,str);
        istringstream iss(str);
        v.clear();
        int x;
        while(iss>>x) v.push_back(x);
        if(v.size()==3) {
          if(v[0]<=v[1]) update(v[0]+1,v[1]+1,1,1,n);
          else {
            update(1,v[1]+1,1,1,n);
            update(v[1]+1,n,1,1,n);
          }
        }else {
                if(v[0]<=v[1]) printf("%d\n",Query(v[0]+1,v[1]+1,1,1,n));
                else printf("%d\n",min(Query(1,v[1]+1,1,1,n),Query(v[1]+1,n,1,1,n)));
        }
        cout<<"========================================="<<endl;
        Print(1,n,1);
        cout<<"========================================="<<endl;
    }
  }
