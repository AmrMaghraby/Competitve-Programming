 ///IN THE NAME OF ALLAH  
 ///IN THE NAME OF ALLAH  
 ///IN THE NAME OF ALLAH  
 #include<bits/stdc++.h>
 using namespace std;
 char grid[10][10];
 bool valid(int x,int y){
  return x>=0&&x<8&&y>=0&&y<8;
 }
 bool f=0;
 bool DFS(int i,int j,queue< pair<int,int> > q,int vis[10][10]){
 if(vis[i][j]==1)
    return false;
 if(grid[i][j]=='A')
    return true;
 int cnt=1;
 while(cnt<=8){
 cnt++;
  int S = q.size();
  while(S--&&f==1){
    int t1 = q.front().first;
    int t2 = q.front().second;
    //cout<<t1<<" "<<t2<<" "<<i<<" "<<j<<endl; 
    q.pop();
    if(t1+1<=7)
      q.push(make_pair(t1+1,t2));
    if(((t1+1==i)||(t1==i))&&t2==j){
      // cout<<"D"<<endl; 
       return false;
     }
 }
 f=1;
 vis[i][j]=1;
 bool f1,f2,f3,f4,f5,f6,f7,f8;
 if(valid(i+1,j))
   f1 = DFS(i+1,j,q,vis);
 if(valid(i,j+1))
   f2 = DFS(i,j+1,q,vis);
 if(valid(i-1,j))
   f3 = DFS(i-1,j,q,vis);
 if(valid(i,j-1))
   f4 = DFS(i,j-1,q,vis);
 if(valid(i-1,j-1))
   f5 = DFS(i-1,j-1,q,vis);
 if(valid(i+1,j+1))
   f6 = DFS(i+1,j+1,q,vis);
 if(valid(i-1,j+1))
   f7 = DFS(i-1,j+1,q,vis);
 if(valid(i+1,j-1))
   f8 = DFS(i+1,j-1,q,vis);
 bool ret = (f1 || f2 || f3 || f4 || f5 || f6 || f7 || f8);
   if(ret==true)
     return ret;
  }
return false;
}
 int main(){
 int vis[10][10];
 queue<pair<int,int>> q;
 for(int i=0;i<8;i++)
  for(int j=0;j<8;j++){
   cin >> grid[i][j];
   if(grid[i][j]=='S')
    q.push(make_pair(i,j));
   vis[i][j]=0;
  }
 if(DFS(7,0,q,vis))
   cout<<"WIN";
 else
   cout<<"LOSE";
 }
