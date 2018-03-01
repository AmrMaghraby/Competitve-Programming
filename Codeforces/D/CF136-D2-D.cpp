 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 struct Point{
    int x, y;
 };
 double sqr(double X){
   return 1LL*X*X;
 }
 vector<Point>vec;
 int distSq(Point p, Point q){
     return (p.x - q.x)*(p.x - q.x)+(p.y - q.y)*(p.y - q.y);
 }
 bool isSquare(Point p1, Point p2, Point p3, Point p4){
    int d2 = distSq(p1, p2);
    int d3 = distSq(p1, p3);
    int d4 = distSq(p1, p4);
    if (d2 == d3 && 2*d2 == d4){
        int d = distSq(p2, p4);
        return (d == distSq(p3, p4) && d == d2);
    }
    if (d3 == d4 && 2*d3 == d2){
        int d = distSq(p2, p3);
        return (d == distSq(p2, p4) && d == d3);
    }
    if (d2 == d4 && 2*d2 == d3){
        int d = distSq(p2, p3);
        return (d == distSq(p3, p4) && d == d2);
    }
    return false;
 }
 double T,TT;
 bool isRec(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
  double cx,cy;
  double dd1,dd2,dd3,dd4;
  T=cx=(x1+x2+x3+x4)/4.0;
  TT=cy=(y1+y2+y3+y4)/4.0;
  dd1=sqr(cx-x1)+sqr(cy-y1);
  dd2=sqr(cx-x2)+sqr(cy-y2);
  dd3=sqr(cx-x3)+sqr(cy-y3);
  dd4=sqr(cx-x4)+sqr(cy-y4);
  return abs(dd1-dd2) < 1e-7 && abs(dd1-dd3)<1e-7 && abs(dd1-dd4)<1e-7;
 }
 int main() {

   for(int i=0;i<8;i++){
     Point P;
     cin >> P.x >> P.y;
     vec.push_back(P);
   }
   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
     if(i==j) continue;
      for(int k=0;k<8;k++){
       if(j==k || i==k) continue;
        for(int l=0;l<8;l++){
           vector<int>vec3;
           for(int tmp=0;tmp<8;tmp++)
              if(tmp!=i && tmp!=j && tmp!=k && tmp!=l)
                   vec3.push_back(tmp);
         if(i==l || j==l || k==l ) continue;

          bool f = isSquare(vec[i],vec[j],vec[k],vec[l]);
          bool ff = isRec(vec[vec3[0]].x,vec[vec3[0]].y,vec[vec3[1]].x,vec[vec3[1]].y,vec[vec3[2]].x,vec[vec3[2]].y,vec[vec3[3]].x,vec[vec3[3]].y);
          if(f&&ff){
           cout<<"YES"<<endl;
           cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
           cout<<vec3[0]+1<<" "<<vec3[1]+1<<" "<<vec3[2]+1<<" "<<vec3[3]+1;
           return 0;
          }
        }
      }
    }
   }
    cout<<"NO";
    return 0;
 }





