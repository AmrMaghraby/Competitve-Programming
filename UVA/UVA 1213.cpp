 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 vector<int>vec;
 bool Primes[10000];
 int n,k;
 long long mem[1127][2000][16];
 long long dp(int Sum,int i,int M){
  if(M==k) return Sum==n;
  if(n<vec[i] || Sum>n) return 0;
  if(mem[Sum][i][M]!=-1)
     return mem[Sum][i][M];
  return mem[Sum][i][M]=dp((Sum+vec[i]),i+1,M+1)+dp(Sum,i+1,M);
 }
 int main(){
  for(int i=2;i<2000;i++) Primes[i]=1;
  for(int i=0;i<2000;i++)
    if(Primes[i])
       for(int j=i+i;j<2000;j+=i)
          Primes[j]=0;
  for(int i=0;i<2000;i++)
      if(Primes[i]) vec.push_back(i);
  while(cin >> n >> k){
    if(!n&&!k) break;
    memset(mem,-1,sizeof mem);
    cout<<dp(0,0,0)<<endl;;
  }

}
