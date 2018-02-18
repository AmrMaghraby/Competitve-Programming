 #include<bits/stdc++.h>
 using namespace std;
 struct Rec{
   double x1,x2,y1,y2;
 };
 struct Circle{
  double x1,y1,r;
 };
 struct Points{
  double x1,y1;
 };
 vector<pair< Rec , int > > v1;
 vector<pair<Circle , int > > v2;
 vector< pair<int,int> > ans;
 bool validR(Rec r,Points P){
   if(P.x1>r.x1 && P.x1<r.x2)
     if(P.y1<r.y1 && P.y1>r.y2)
         return true;
   return false;
 }
 bool validC(Circle C,Points P){
   return ((C.x1-P.x1)*(C.x1-P.x1)+(C.y1-P.y1)*(C.y1-P.y1)) < (C.r*C.r);
 }
 int main(){
  int i=0;
  while(true){
       char c;
       cin >> c;
       if(c=='*') break;
       if(c=='r'){
         Rec r;
         cin >> r.x1 >> r.y1>>r.x2>>r.y2;
         v1.push_back({r,i});
       }else {
         Circle c;
         cin >> c.x1 >> c.y1 >> c.r;
         v2.push_back({c,i});
       }
   i++;
  }
  int j=0;
  while(true){
    Points P;
    bool f=0;
    cin >> P.x1 >> P.y1;
    if(P.x1==9999.9 && P.y1==9999.9) break;
    for(int i=0;i<v1.size();i++){
      if(validR(v1[i].first,P))
         ans.push_back({j,v1[i].second}),f=1;
    }
    for(int i=0;i<v2.size();i++){
      if(validC(v2[i].first,P)){
         ans.push_back({j,v2[i].second}),f=1;
      }
    }
    if(!f) ans.push_back({j,1e9});
  j++;
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
     if(ans[i].second==1e9)
         cout<<"Point "<<ans[i].first+1<<" is not contained in any figure"<<endl;
     else cout<<"Point "<<ans[i].first+1<<" is contained in figure "<<ans[i].second+1<<endl;
  }
 }

