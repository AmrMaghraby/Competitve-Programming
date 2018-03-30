
 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 long long s[400001],Arr[400001];
 int n;
 bool B[400000];
 map<int , vector<int> > mp;
 void Build(int id,int l ,int r){
   if(l==r){
     s[id]=Arr[l];
     return ;
   }
   int mid = (l+r)/2;
   Build(id*2,l,mid);
   Build(id*2+1,mid+1,r);
   s[id] = min(s[2*id] , s[2*id+1]);
 }
 long long Query(int x,int y,int id ,int l,int r){
  if( x > r || y < l ) return 1e9;
  if( x<=l && y>=r ) return s[id];
  int mid = (l+r)/2;
  return s[id]=min(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid+1,r));
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
  int id=1;
  while(cin >> n)
    {
      memset(s,0,sizeof s);
      memset(Arr,0,sizeof Arr);
      memset(B,0,sizeof B);
      mp.clear();
      for(int i=1;i<=n;i++){
        cin >> Arr[i];
        mp[Arr[i]].push_back(i);
      }
      Build(1,1,n);
      ///Print(1,n,1);
      ///cout<<Query(2,4,1,1,n)<<endl;
      long long ans=0;
      for(int i=1;i<=n;i++){
        if(B[Arr[i]]) continue;
        B[Arr[i]]=1;
        int f=0;
        for(int j=0;j<mp[Arr[i]].size();j++){
          ///cout<<"aaa"<<f<<endl;
          if(mp[Arr[i]].size()!=1)
           {
              if(j<mp[Arr[i]].size()-1)
              {
             ///    cout<<Arr[i]<<" "<<i<<" "<<mp[Arr[i]][j]<<" "<<mp[Arr[i]][j+1]<<" "<<Query(mp[Arr[i]][j],mp[Arr[i]][j+1],1,1,n)<<endl;
                 if(Query(mp[Arr[i]][j],mp[Arr[i]][j+1],1,1,n)<Arr[i])///{
                                    ///cout<<f<<"  ";
                                    f++;///cout<<"dd"<<f<<endl;///}
              }
           }
           ///cout<<"ddd"<<f<<endl;
           }
          ///cout<<f<<endl;
          if(f)ans+=(f+1);
          else ans++;
         /// cout<<"aaaaaaaaaaaaaaaaaa"<<endl;
      }
      printf("Case %d: %d\n",id++,ans);
    }
 }


