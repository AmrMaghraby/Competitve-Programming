 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 queue<int>Q;
 pair<int,int>pa[100000];
 vector< pair<int,int> >vec;
 int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
   int a,b;
   cin >> a >> b;
   pa[i]={a,b};
   if(a==1) Q.push(i);
  }
  while(!Q.empty()){
    int T = Q.front();
    Q.pop();
    if(pa[T].first==0) continue;
    vec.push_back({T,pa[T].second});
    pa[pa[T].second].first -=1 ;
    pa[pa[T].second].second = pa[pa[T].second].second ^ T;
    if(pa[pa[T].second].first==1) Q.push(pa[T].second);
  }
  cout<<vec.size()<<endl;
  for(int i=0;i<vec.size();i++)
    cout<<vec[i].first<<" "<<vec[i].second<<endl;
 }
