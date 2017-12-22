// A C++ program to check if two given line segments intersect
#include <iostream>
using namespace std;
struct Point{
    int x;
    int y;
};
bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}
bool inrect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int  minx,miny,maxx,maxy;
    minx=min(x3,x4);miny=min(y3,y4);
    maxx=max(x3,x4);maxy=max(y3,y4);
    if(minx<=x1 && maxx>=x1 && miny<=y1 && maxy>=y1 && minx<=x2 && maxx>=x2 && miny<=y2 && maxy>=y2)
        return true;
    else
        return false;
}
int main(){
  int Tc;
  cin >> Tc;
  while(Tc--){
   int a,b,c,d,e,f,g,h;
   cin >> e >> f >> g >> h >> a >> b >> c >> d;
   struct Point P1 = {a,b};
   struct Point P2 = {c,d};
   ///Other Verticies
   struct Point P3 = {a,d};
   struct Point P4 = {c,b};
   ///Line Points
   struct Point P5 = {e,f};
   struct Point P6 = {g,h};
   if(P1.x > P2.x)
     swap(P1.x,P2.x);
   if(P2.y > P1.y)
     swap(P2.y,P1.y);
   if(doIntersect(P1,P4,P5,P6))
     cout<<'T';
    else if(doIntersect(P1,P3,P5,P6))
     cout<<'T';
    else if(doIntersect(P3,P2,P5,P6))
     cout<<'T';
    else if(doIntersect(P2,P4,P5,P6))
     cout<<'T';
    else if(inrect(P5.x,P5.y,P6.x,P6.y,P1.x,P1.y,P2.x,P2.y))
        cout<<'T';
    else cout<<'F';
    cout<<endl;
  }
}


