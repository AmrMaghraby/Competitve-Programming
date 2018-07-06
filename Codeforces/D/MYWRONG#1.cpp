
 ///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
int B, P[123456],a[123456];
vector<int>vec[123456];
vector<int>ind;
bool vis[123456];
int Arr[123456];
map<int,bool>mp;
int in[100000];
void DFS(int i,int prev){
 vis[i]=1;
 for(int j=0;j<vec[i].size();j++){
   if(!vis[vec[i][j]] && prev != vec[i][j])
     DFS(vec[i][j],i);
   else if(vis[vec[i][j]] &&  prev != vec[i][j] && !mp.count(i) &&!mp.count(vec[i][j])) ind.push_back(i),mp[i]=1;
   else if(i==vec[i][j] && !mp.count(i)&&!mp.count(vec[i][j])) ind.push_back(i),mp[i]=1;
 }
}
int main(){
    int n;
    scanf("%d" , &n);
    for(int i=1;i<=n;i++){
       scanf("%d",&Arr[i]);
       vec[i].push_back(Arr[i]);
       if(i!=Arr[i]) vec[Arr[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
          DFS(i,i);
    int Ans = ind.size()-1;
    for(int i=0;i<ind.size()-1;i++)
      Arr[ind[i]]=ind[ind.size()-1];
    ///CHECK
    bool f=0;
    for(int i=1;i<=n;i++)
     if(i==Arr[i])
        f=1;
    if(f){
            cout<<Ans<<endl;
            for(int i=1;i<=n;i++)
              cout<<Arr[i]<<" ";
    }else{
          for(int i=1;i<=n;i++)
             in[Arr[i]]++;
          int ind;
          for(int i=1;i<=n;i++)
             if(in[i]>=1 && in[Arr[i]]>1){
               ind=i;
               cout<<i<<" "<<Arr[i]<<" "<<Arr[Arr[i]]<<endl;
             }
           cout<<endl<<endl<<ind<<endl<<endl;
          cout<<Ans+1<<endl;
          for(int i=1;i<=n;i++){
             if(i!=ind) cout<<Arr[i]<<" ";
             else cout<<ind<<" ";
          }
    }
}

