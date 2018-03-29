
 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 #define ll long long
 using namespace std;
 long long seg[200005*5],lazy[200005*5],Arr[200005*5];
 vector<int> v;
 void Build(int id,int l ,int r){
   if(l==r){
      seg[id]=Arr[l];
    return ;
   }
   int mid = (l+r)/2;
   Build(id*2,l,mid);
   Build(id*2+1,mid+1,r);
   seg[id] = min(seg[2*id] , seg[2*id+1]);
   return ;
 }
 void update(ll s,ll e,ll p,ll from,ll to){
  if(from<=s&&e<=to){
   lazy[p]+=v[2];
   return;
  }
  if(s>to||e<from)return;
  ll mid=(s+e)/2;
  update(s,mid,p*2,from,to);
  update(mid+1,e,p*2+1,from,to);
  seg[p]=min(seg[p*2]+lazy[p*2],seg[p*2+1]+lazy[p*2+1]);
 }
 ll query(ll s,ll e,ll p,ll from,ll to){
  if(s>to||e<from) return 1e9;
  if(s==e)return seg[p]+lazy[p];
  if(from<=s&&e<=to) return seg[p]+lazy[p];
  ll mid=(s+e)/2;
  ll a=query(s,mid,p*2,from,to);
  ll b=query(mid+1,e,p*2+1,from,to);
  return min(a,b)+lazy[p];
 }
 int main(){
     int n ,m,tc;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%lld",&Arr[i]);
      Build(1,1,n);
     cin >> m;
     cin.ignore();
     for(int i=0;i<m;i++){
        string str;
        getline(cin,str);
        istringstream iss(str);
        v.clear();
        int x;
        while(iss>>x) v.push_back(x);
        if(v.size()==3) {
          if(v[0]<=v[1]) update(1,n,1,v[0]+1,v[1]+1);
          else {
            update(1,n,1,1,v[1]+1);
            update(1,n,1,v[0]+1,n);
          }
        }else {
                if(v[0]<=v[1]) printf("%lld\n",query(1,n,1,v[0]+1,v[1]+1));
                else printf("%lld\n",min(query(1,n,1,1,v[1]+1),query(1,n,1,v[0]+1,n)));
        }
     }
 }



