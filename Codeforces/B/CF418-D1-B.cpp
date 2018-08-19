 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 const double PI = 3.141592653;
 using namespace std;
 int DPP[101][1048579];
 struct Data{
   int Cost,b;
   vector<int>MI;
 };
 vector<Data>Elements;
 int n,m,b;
 long long DP(int i,int m,int Mask){
   if(Mask==1048575)
     return 0;
   if(DPP[i][Mask]!=-1)
     return DPP[i][Mask];
   long long Mi=1e9;
   for(int i=0;i<n;i++)
     Mi = min(DP(i,m,Mask),DP(i+1,m,Mask|(i<<1))+Elements[i].Cost);
   return DPP[i][m][Mask]=Mi;
 }
 int main(){
  cin >> n>>m>>b;
  memset(DPP,-1,sizeof DPP);
  for(int i=0;i<n;i++){
    Data D1;
    cin >> D1.Cost >> M >> D1.b;
    for(int j=0;j<M;j++){
     int a;
     cin >> a;
     D1.MI.push_back(a);
    }
    Elements.push_back(D1);
  }
  cout<<DP(0,0,0);
 }
