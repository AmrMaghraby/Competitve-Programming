/// in the name of allah
#include<bits/stdc++.h>
using namespace std;
struct Line{
   int sx,sy;
   int ex,ey;
};
vector<Line>L;
bool slope(int index){
 if(!(L[index].ex-L[index].sx))
     return 0;
 double S = 1.0*(L[index].ey-L[index].sy)/(L[index].ex-L[index].sx);
 return S<0;
}
int main(){
 int Tc;
 cin >> Tc;
 while(Tc--){
     int n;
     cin >> n;
     for(int i=0;i<n;i++){
      int a,b,c,d;
      cin >> a >> b >> c >> d;
      L.push_back({a,b,c,d});
     }
     int m;
     cin >> m;
     while(m--){
       int a,b;
       cin >> a >> b;
       int mn = 1e9;
       for(int i=0;i<n;i++){
        if(a>=L[i].sx && a <= L[i].ex && b>=L[i].sy && b>=L[i].ey){
            if(slope(i)){
              mn=min(mn,L[i].ex);
            }
            else mn=min(mn,L[i].sx);
        }
       }
       if(mn==1e9) cout<<a<<endl;
       else cout<<mn<<endl;
     }
    }
}

