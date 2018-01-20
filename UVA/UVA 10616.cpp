 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 vector<int>A;
 int D,N,n,x;
 long long mem[222][11][22];
 long long Recur(int i,int M, int Sum){
  if(M==N){
      return Sum%D==0?1:0;
      return 0;
   }
   if(i==n) return 0;
   if(mem[i][M][Sum]!=-1)
     return mem[i][M][Sum];
   return mem[i][M][Sum]=Recur(i+1,M,Sum) + Recur(i+1,M+1,(((Sum+A[i])%D)+D)%D);
 }
 int main(){
  int id=0;
  while(true){
    id++;
    cin >> n >> x;
    if(!n&&!x)
      return 0;
    A.clear();
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      A.push_back(a);
    }
    cout<<"SET "<<id<<":"<<endl;
    int test=0;
    while(x--){
     test++;
     cout<<"QUERY "<<test<<": ";
     cin >> D >> N;
     memset(mem,-1,sizeof  mem);
     cout<<Recur(0,0,0)<<endl;
    }
  }
 }
