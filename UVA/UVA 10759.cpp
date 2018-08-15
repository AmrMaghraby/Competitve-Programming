#include <bits/stdc++.h>
using namespace std;
int n,Sum,cnt1;
int main(){
  while(true){

  memset(DPP,-1,sizeof DPP);
  cin >> n >> Sum;
  if(n==0&&Sum==0)break;
   long long D = DP(0,0,0);
   long long Power = power(6,n);

   if(D%Power==0)
     cout<<D/Power<<endl;
   else {
    long long gcd = __gcd(D,Power);
    cout<<D/gcd<<"/"<<Power/gcd<<endl;
   }

  }
}
