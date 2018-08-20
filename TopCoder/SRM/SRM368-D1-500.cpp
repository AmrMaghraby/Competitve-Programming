///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
struct Poly{
  vector<pair<int,int> > points;
};
vector<int>Comp[10000];
vector<Poly>vec;
bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}
int main(){
 string S;
 while(cin >> S){
   cout<<S<<endl;
   Poly T;
   for(int i=0;i<S.size();i++){
       if(S[i]=='-')continue;
       string x = S.substr(i,(find(S.begin()+i,S.end(),',')-S.begin())-i);
       int mul=10,cons=0;
       for(int j=0;j<x.size();j++){
          if(j==0) cons+=x[j]-'0';
          else {
            cons+=(x[j]-'0')*mul;
            mul*=10;
          }
       }
       int xx=cons;
       i=(find(S.begin()+i,S.end(),',')-S.begin())+1;
       string y=S.substr(i,(find(S.begin()+i,S.end(),'-')-S.begin())-i);
       mul=10,cons=0;
       for(int j=0;j<y.size();j++){
          if(j==0) cons+=y[j]-'0';
          else {
            cons+=(y[j]-'0')*mul;
            mul*=10;
          }
       }
       int yy = cons;
      /// cout<<xx<<" "<<yy<<endl;
       i=(find(S.begin()+i,S.end(),'-')-S.begin());
       T.points.push_back(make_pair(xx,yy));
   }
   vec.push_back(T);
 }
 for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].points.size();j++){
      for(int k=0;k<vec.size();k++){
       if(k==i) continue;
       for(int r=0;r<vec[k].points.size(),r++){
        if(SegmentIntersect(i,j,k,r)){
          Comp[i].push_back(k);
          Comp[k].push_back(i);
        }
       }
      }
 ///    cout<<"Polyline "<<i<<" "<<vec[i].points[j].first<<" "<<vec[i].points[j].second<<endl;
  }
 }

}
