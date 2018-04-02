 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 queue< pair<int,int> > q,q2;
 map<pair<int,int>,int>mp;
 int main(){
 long long n,x,y,c,ans=0;
 cin >> n >> x >> y >> c;
 q.push({x,y});
  for(int counter = 1;counter < c;){
    while(!q.empty()){
      x = q.front().first;
      y = q.front().second;
      q.pop();
      cout<<"1  "<<x<<" "<<y<<endl;
      if(mp[{x+1,y}])
           continue;
      else if(x+1<=n)
           q2.push({x+1,y});
      if(mp[{x-1,y}])
           continue;
      else if(x-1>=0)
           q2.push({x-1,y});
      if(mp[{x,y+1}])
           continue;
      else if(y+1<=n)
           q2.push({x,y+1});
      if(mp[{x,y-1}])
           continue;
      else if(y-1>=0)
           q2.push({x,y-1});
      mp[{x+1,y}]=1;
      mp[{x,y+1}]=1;
      mp[{x-1,y}]=1;
      mp[{x,y-1}]=1;
    }
   while(!q2.empty()){
      x = q2.front().first;
      y = q2.front().second;
      q2.pop();
      cout<<"2  "<<x<<"       "<<y<<endl;
      if(mp[{x+1,y}])
           continue;
      else if(x+1<=n)
           q.push({x+1,y});
      if(mp[{x-1,y}])
           continue;
      else if(x-1>=0)
           q.push({x-1,y});
      if(mp[{x,y+1}])
           continue;
      else if(y+1<=n)
           q.push({x,y+1});
      if(mp[{x,y-1}])
           continue;
      else if(y-1>=0)
           q.push({x,y-1});
      mp[{x+1,y}]=1;
      mp[{x,y+1}]=1;
      mp[{x-1,y}]=1;
      mp[{x,y-1}]=1;
    }
    counter+=(q2.size()+q.size());
    ans++;
    cout<<endl<<"=================================="<<endl;
    cout<<" "<<q.size()<<" "<<q2.size()<<" "<<counter<<"   "<<ans<<endl;
  }
  cout<<ans<<endl;
 }
