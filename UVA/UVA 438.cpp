
///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159265359;
int main(){
 double x,y,x2,y2,x3,y3;
 while(cin >> x >> y >> x2 >> y2 >> x3 >> y3){
   double a=0,b=0,c=0;
   a = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
   b = sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3));
   c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
   double S = (a+b+c)/2;
   double R = (a*b*c)/(2*(sqrt(S*(S-a)*(S-b)*(S-c))));
   R/=2;
   cout<<fixed<<setprecision(2)<<2*PI*R<<endl;
 }
}

