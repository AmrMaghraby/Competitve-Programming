#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159265;
const int INF = INT_MAX;
vector< pair< pair< double , double > , pair< double , double > > >Sorted;
int main(){
 int n;
  cin >> n;
  for(int i=0;i<n;i++){
    double x,y;
    cin >> x >> y;
    double Angle = atan2((y),x)*(180/PI);
    if(Angle<0.0)
      Angle+=360;
    Sorted.push_back({{Angle,sqrt((x*x)+(y*y))},{x,y}});
  }
 sort(Sorted.begin(),Sorted.end());
  for(int i=0;i<Sorted.size();i++)
       cout<<Sorted[i].second.first<<" "<<Sorted[i].second.second<<endl;
}
