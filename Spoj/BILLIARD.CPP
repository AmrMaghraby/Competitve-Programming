 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 const double PI = 3.141592653;
 using namespace std;
 int main(){

  int a,b,n,m,s;
  while(cin >>a>>b>>s>>m>>n){
    if(!a&&!b&&!s&&!m&&!n) break;
    double lb = n*b,la=m*a;
    double velocity = sqrt(lb*lb+la*la)/s;
    double Angle = atan(lb/la)*180/PI;
    printf("%.2f %.2f\n",Angle,velocity);
  }
 }
