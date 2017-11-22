///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
 const double EPS  = 1e-9 ;
 int main(){
  double n;
  cin >> n;
  double x = n+1;
  long long y = (1.0*n*x)/(x-n);
  if(n!=x&&x!=y&&y!=n)
    cout<<n<<" "<<x<<" "<<y;
  else cout<<"-1";
 }

