 #include <bits/stdc++.h>
 using namespace std;
 struct Rect{
  int x,y,xx,yy;
  int x3,y3,x4,y4;
  int Area;
 };
 struct Segment{
  int x,y,xx,yy;
 };
 vector<Rect> input;
 vector<Segment> inputL;
 bool Contain(Rect p , Segment s){
  return (s.x > p.x && s.x < p.xx && s.y > p.y && s.y < p.yy)||
  (s.xx > p.x && s.xx < p.xx && s.yy > p.y && s.yy < p.yy);
 }
 struct Point{
    int x;
    int y;
 };
 int ccw(Point p0,Point p1,Point p2){
  int dx1=p1.x-p0.x,
    dy1=p1.y-p0.y,
    dx2=p2.x-p0.x,
    dy2=p2.y-p0.y;
  if(dy1*dx2>dx1*dy2)
    return -1;
  if(dy1*dx2<dx1*dy2)
    return 1;
  if(dx1*dx2<0 || dy1*dy2<0)
    return 1;
  if(dx1*dx1+dy1*dy1 > dx2*dx2+dy2*dy2)
    return -1;
  return 0;
 }
 int intersect(Point p0,Point p1,Point p2,Point p3){
  return ccw(p0,p2,p1)*ccw(p0,p3,p1)<=0 &&
    ccw(p2,p0,p3)*ccw(p2,p1,p3)<=0;
 }
 bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
 }
 int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
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
 int main(){
    for(int i=0;;i++){
      string x1,y1,x2,y2;
      cin >> x1;
      if(x1=="ss")
        break;
      cin >> y1 >> x2 >> y2;
      istringstream iss (x1);
      int x,y,xx,yy;
      iss >> x;
      istringstream iss1 (y1);
      iss1 >> y;
      istringstream iss2 (x2);
      iss2 >> xx;
      istringstream iss3 (y2);
      iss3 >> yy;
      Rect p;
      p.x = x;
      p.y = y;
      p.xx=xx;
      p.yy=yy;
      p.x3=x;
      p.y3=yy;
      p.x4=xx;
      p.y4=y;
      p.Area = (abs(xx-x)*abs(yy-y));
      input.push_back(p);
    }
   for(int i=0;;i++){
      string x1,y1,x2,y2;
      cin >> x1;
      if(x1=="ss")
        break;
      cin >> y1 >> x2 >> y2;
      istringstream iss (x1);
      int x,y,xx,yy;
      iss >> x;
      istringstream iss1 (y1);
      iss1 >> y;
      istringstream iss2 (x2);
      iss2 >> xx;
      istringstream iss3 (y2);
      iss3 >> yy;
      Segment s;
      s.x = x;
      s.y = y;
      s.xx=xx;
      s.yy=yy;
      inputL.push_back(s);
    }
    long long ans1=0,ans2=0;
    for(int i=0;i<input.size();i++){
     bool flag1=false,flag2=false;
     for(int j=0;j<inputL.size();j++){
          Point p1;Point Sp;
          Point p2;Point Sp2;
          Point p3;
          Point p4;
          Sp.x = inputL[j].x;   Sp.y = inputL[j].y;
          Sp2.x = inputL[j].xx; Sp2.y = inputL[j].yy;
          p1.x = input[i].x;   p1.y = input[i].y;
          p2.x = input[i].xx;  p2.y = input[i].yy;
          p3.x = input[i].x3;  p3.y = input[i].y3;
          p4.x = input[i].x4;  p4.y = input[i].y4;
          if(Contain(input[i],inputL[j]) && !flag1)
               flag1=1;
          else if(intersect(p1,p2,Sp,Sp2)||intersect(p2,p3,Sp,Sp2)||intersect(p3,p4,Sp,Sp2)||intersect(p4,p1,Sp,Sp2))
             if(!flag2) flag2=1;
      }
      if(flag1)
               ans1+=input[i].Area;
      else if(flag2)
               ans2+=input[i].Area;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
 }
/*
-891 -869 -853 -842
-857 -399 -744 -231
-910 -55  -856   36
-844 287  -749   548
-809 627  -782   954
-704 -803 -641 -663
-684 -330 -558 -268
-702 -40 -545 98
-660 386 -528 586
-697 855 -571 962
-414 -678 -168 -648
-401 -559 -383 -441
-387 5 -263 51
-389 220 -194 448
-361 673 -175 753
68 -912 95 -742
-24 -521 24 -227
30 -70 38 -2
-111 297 14 356
7 797 27 809
368 -709 418 -614
247 -453 344 -251
385 -111 417 -33
275 202 290 421
265 604 278 921
524 -861 655 -640
555 -336 576 -305
429 28 578 35
480 324 704 520
444 632 665 842
932 -954 981 -931
930 -537 939 -455
735 -81 787 192
830 316 869 589
808 629 971 666
ss
-898 -383 126 12
283 -716 545 -918
-299 333 54 138
-901 129 706 488
-8 690 -290 955
-590 -771 476 257
-528 -518 651 -139
-984 -848 -380 459
-358 924 31 -617
817 -904 -208 -401
-657 -211 275 -407
-427 -699 -460 876
403 -612 -675 563
-782 -197 845 816
-492 -771 -342 -83
-650 -208 393 -614
-67 -290 135 -610
68 650 -366 560
-482 608 -525 516
548 460 -95 -436
461 -457 -491 -846
-672 728 -764 548
-301 633 -613 278
-496 126 940 576
-350 -378 -671 1000
148 82 275 211
815 872 -810 -362
160 -367 -754 569
-721 941 -405 -57
-792 582 804 563
-934 -115 -641 -737
ss

*/
/*
 0 0 1 1
 2 0 3 1
 4 0 5 1
 6 0 7 1
 8 0 9 1
 10 0 11 1
 12 0 13 1
 14 0 15 1
 16 0 17 1
 18 0 19 1
 20 0 21 1
 22 0 23 1
 24 0 25 1
 26 0 27 1
 28 0 29 1
 30 0 31 1
 32 0 33 1
 34 0 35 1
 36 0 37 1
 38 0 39 1
 40 0 41 1
 42 0 43 1
 44 0 45 1
 46 0 47 1
 48 0 49 1
 50 0 51 1
 52 0 53 1
 54 0 55 1
 56 0 57 1
 58 0 59 1
 60 0 61 1
 62 0 63 1
 64 0 65 1
 66 0 67 1
 68 0 69 1
 70 0 71 1
 72 0 73 1
 74 0 75 1
 76 0 77 1
 78 0 79 1
 80 0 81 1
 82 0 83 1
 84 0 85 1
 86 0 87 1
 88 0 89 1
 90 0 91 1
 92 0 93 1
 94 0 95 1
 96 0 97 1
 98 0 99 1*/
/*
 41 -1 43 2
 34 -1 34 2
 69 -1 73 2
 78 -1 81 2
 62 -1 66 2
 5 -1 5 2
 81 -1 83 2
 61 -1 62 2
 95 -1 97 2
 27 -1 28 2
 91 -1 95 2
 2 -1 5 2
 92 -1 94 2
 21 -1 22 2
 18 -1 18 2
 47 -1 48 2
 71 -1 74 2
 69 -1 71 2
 67 -1 71 2
 35 -1 39 2
 3 -1 4 2
 22 -1 25 2
 73 -1 77 2
 41 -1 42 2
 53 -1 56 2
 47 -1 51 2
 62 -1 64 2
 37 -1 41 2
 23 -1 24 2
 29 -1 32 2
 16 -1 16 2
 90 -1 92 2
 88 -1 89 2
 40 -1 42 2
 64 -1 67 2
 46 -1 46 2
 90 -1 94 2
 70 -1 70 2
 6 -1 7 2
 93 -1 96 2
 29 -1 32 2
 84 -1 88 2
 56 -1 56 2
 66 -1 67 2
 31 -1 34 2
 44 -1 48 2
 26 -1 29 2
 37 -1 40 2
 18 -1 20 2
 29 -1 30 2
*/
