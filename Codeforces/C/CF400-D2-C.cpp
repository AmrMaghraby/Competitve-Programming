 #include<bits/stdc++.h>
 using namespace std;
 vector< pair<int,int> > vec;
 int main(){
 int n,m,x,y,z,p;
 cin >> n >> m >> x >> y >> z >> p;
 x%=4;y%=2;z%=4;
 for(int i=0;i<p;i++){
  int a,b;
  cin >> a >> b;
  vec.push_back({a,b});
 }
 while(x--){
    for(int i=0;i<vec.size();i++){
       int temp = vec[i].first;
       vec[i].first=vec[i].second;
       vec[i].second=n-temp+1;
    }
  swap(n,m);
 }
 if(y)
   for(int i=0;i<vec.size();i++)
     vec[i].second=m-vec[i].second+1;
 int cnt=0;
 while(z){
    for(int i=0;i<vec.size();i++){
       int temp = vec[i].first;
       vec[i].first=vec[i].second;
       vec[i].second=n-temp+1;
    }
    cnt++;
    if(cnt==3){
        cnt=0;
        z--;
    }
        swap(n,m);
 }
 for(int i=0;i<vec.size();i++)
   cout<<vec[i].first<<" "<<vec[i].second<<endl;
}

