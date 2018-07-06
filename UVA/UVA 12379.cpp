 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int Vis,mx;
 bool VIS[10009];
 vector<int>vec[10009];
 long long ans;
 void DFS(int i, int prev,int cnt){
   VIS[i]=1;
   if(cnt>mx){
      mx=cnt;
      Vis=i;
   }
   bool f=0;
   for(int j=0;j<vec[i].size();j++){
       if(!VIS[vec[i][j]] && vec[i][j]!=prev){
            DFS(vec[i][j],i,cnt+1);
            f=1;
       }
   }
 }
 int main(){
   int Tc;
   cin >> Tc;
   while(Tc--){
     memset(VIS,0,sizeof VIS);
     for(int i=0;i<10000;i++)
        vec[i].clear();
     mx=0;
     int n;
     cin >> n;
     for(int i=1;i<=n;i++){
       int a;
       cin >> a;
       while(a--){
         int b;
         cin >> b;
         vec[i].push_back(b);
       }
     }
    DFS(1,-1,0);
    memset(VIS,0,sizeof VIS);
    DFS(Vis,-1,0);
    cout<<2*(n-(mx+1))+mx<<endl;
   }
 }
