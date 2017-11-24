#include<bits/stdc++.h>
using namespace std;
vector< pair<int ,int > >vec;
vector<int>NotSorted;
vector<int>adjlist[3000];
int main(){
 int n,m;
 cin >> n >> m;
 vec.push_back({0,0});
 NotSorted.push_back(0);
 for(int i=1;i<=n;i++){
   int a;
   cin >> a;
   vec.push_back({a,i});
   NotSorted.push_back(a);
 }
 for(int i=0;i<m;i++){
   int a,b;
   cin >> a >> b;
   adjlist[a].push_back(b);
   adjlist[b].push_back(a);
 }
 sort(vec.begin(),vec.end());
 long long ans=0;
 for(int i = n ; i>=1 ; i--){
   for(int j=0;j<adjlist[vec[i].second].size();j++)
        ans+=NotSorted[adjlist[vec[i].second][j]];
    NotSorted[vec[i].second]=0;
 }
 cout<<ans;
}


