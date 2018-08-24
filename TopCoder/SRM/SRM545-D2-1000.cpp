///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
class SpacetskE {
  public:
    int gcd(int a, int b){
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int c = b;
            b = a % b;
            a = c;
        }
        return a;
    }
    int countsets(int l,int h,int k){
     if(k==1) return (l+1)*(h+1);
     int c[333][333]={};
     for(int i=0;i<=300;i++){
      c[i][0]=1;
      for(int j=1;j<=i;j++)
       c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
     }
     long long res=0;
     for(int x=0;x<=l;x++){
        for(int dx=-l;dx<=l;dx++)
         for(int dy=1;dy<=h;dy++){
            if(gcd(dx,dy)==1){
                int t=0,y=0,xx=x;
                while(xx>=0&&xx<=l&&y<=h){
                     t++;
                     xx+=dx;
                     y+=dy;
                }
                res=(res + c[t][k])%mod;
            }
         }
     }
     return res;
    }
};
