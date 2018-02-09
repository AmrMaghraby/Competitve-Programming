 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 double n;
 pair<pair<double,double>,double>p[300];
 bool mp[200][200];
 bool vis[200];
 long long mx=-1e9;
 bool dist(pair<pair<double,double>,double>F,pair<pair<double,double>,double>S){
   double dist = sqrt((F.first.first-S.first.first)*(F.first.first-S.first.first)+
   (F.first.second-S.first.second)*(F.first.second-S.first.second));
   return (dist < (F.second+S.second) && (dist > fabs(F.second-S.second)));
 }
 long long dfs(int i){
  vis[i]=1;
  long long cnt=0;
  for(int j=0;j<n;j++)
   if(mp[i][j] && !vis[j]){
      vis[j]=1;
      cnt+=dfs(j)+1;
   }
  return cnt;
 }
 int main(){
  while(cin >> n , n!=-1){
  mx=-1e9;
  memset(p,0,sizeof p);
  memset(mp,0,sizeof mp);
  memset(vis,0,sizeof vis);
  for(int i=0;i<n;i++)
      cin >> p[i].first.first>>p[i].first.second>>p[i].second;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      if(i!=j && dist(p[i],p[j]))
          mp[i][j]=1;
  }
//  for(int i=0;i<n;i++,cout<<endl)
//   for(int j=0;j<n;j++)
//    cout<<mp[i][j]<<" ";
  for(int i=0;i<n;i++)
   if(!vis[i])
    mx=max(mx,dfs(i));

  if(mx==-1e9)
   cout<<"The largest component contains "<<0<<" rings."<<endl;
  else if(mx+1==1)
  cout<<"The largest component contains 1 ring."<<endl;
  else
  cout<<"The largest component contains "<<mx+1<<" rings."<<endl;
  }
 }

