// #include<bits/stdc++.h>
// using namespace std;
// vector<int>X[200000];
// int color[200000];
// int DFS(int a,int b,int prev,bool f,int cnt){
//   cout<<a<<" "<<b<<endl;
//
//   if(a==b)
//      return cnt;
//   if(f==0)
//     color[a]=1;
//   else if(color[a]==1)
//     cnt++;
//   for(int i=0;i<X[a].size();i++)
//     if(prev!=X[a][i])
//       cnt+=DFS(X[a][i],b,a,f,cnt);
//   return cnt;
// }
// int main(){
//  int n,m;
//  cin >> n >> m;
//  for(int i=2;i<=n;i++){
//    int a;
//    cin >> a;
//    X[a].push_back(i);
//    X[i].push_back(a);
//  }
//  for(int i=0;i<m;i++){
//    int s,f,t;
//    cin >> s >> f >> t;
//    int mx=0;
//    int Arr[3]={s,f,t};
//    do{
//        DFS(s,f,-1,0,0);
//        cout<<"================================ 1"<<endl;
//        mx=max(mx,DFS(f,t,-1,1,0));
//        cout<<"================================ 2"<<endl;
//        memset(color,0,sizeof(color));
//    }while(next_permutation(Arr,Arr+3));
//    cout << mx <<endl;
//  }
// }
//

///IN THE NAME OF ALLAH
#include<bits/stdc++.h>
using namespace std;
 struct Point{
    int x;
    int y;
 };
 bool vis[300];
 vector< pair < Point , Point > > X;
 int b,n;
bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
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
bool f=0;
 bool DFS(int a){
  if(a==b-1){
     f=1;
     return 0;
  }
  vis[a]=1;
   for(int i=0;i<n;i++)
   if( vis[i]==0 && i!=a && doIntersect(X[a].first,X[a].second,X[i].first,X[i].second))
                        DFS(i);
 }
int main(){
    int n3;
    cin >> n3;
    while(n3--){
        int n2;
        cin >> n2;
        n=n2;
        X.clear();
        while(n2--){
           int x,y,x2,y2;
           cin >> x >> y >> x2 >> y2;
           Point p = {x,y};
           Point q = {x2,y2};
           X.push_back({p,q});
        }
        int a;
        while(cin >> a >> b){
            if(!a&&!b) break;
            DFS(a-1);
            memset(vis,0,sizeof vis);
            if(f)
                cout<<"CONNECTED"<<endl;
            else
                cout<<"NOT CONNECTED"<<endl;
            f=0;
        }
      if(n3)
            cout<<endl;
    }
 }

