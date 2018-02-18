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
   return ((C.x1-P.x1)*(C.x1-P.x1)+(C.y1-P.y1)*(C.y1-P.y1)) <= (C.r*C.r);
 }
 int main(){
   int T,id=1;
   cin >> T;
   while(T--){
     cout<<"Case "<<id++<<":"<<endl;
     vector<Circle>C2;
     int n,m;
     cin >> n >> m;
     for(int i=0;i<n;i++){
       Circle C;
       cin >> C.x1 >> C.y1 >> C.r;
       C2.push_back(C);
     }
     for(int i=0;i<m;i++){
       Points P;
       bool f=0;
       cin >> P.x1 >> P.y1;
        for(int j=0;j<n;j++)
          if(validC(C2[j],P)){
            cout<<"Yes"<<endl;
            f=1;
            break;
          }
        if(f==0)
            cout<<"No"<<endl;
     }

   }
 }
