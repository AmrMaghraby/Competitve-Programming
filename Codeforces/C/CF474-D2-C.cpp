 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int Tr[2]={1,-1};
 void rotate90(int &x,int &y,int a,int b){
        x-=a,y-=b;
        swap(x,y);
        x*=-1;
        x+=a,y+=b;
        ///XNew = XCos()-YSin()
        ///YNew = XSin()+XCos()
}
 vector< pair<int,int> >vec[4];
 bool square(int i,int j,int k ,int l){

   long long d1 = (vec[0][i].first-vec[1][j].first)*(vec[0][i].first-vec[1][j].first)
   +(vec[0][i].second-vec[1][j].second)*(vec[0][i].second-vec[1][j].second);

   long long d2 = (vec[1][j].first-vec[2][k].first)*(vec[1][j].first-vec[2][k].first)
   +(vec[1][j].second-vec[2][k].second)*(vec[1][j].second-vec[2][k].second);

   long long d3 = (vec[2][k].first-vec[3][l].first)*(vec[2][k].first-vec[3][l].first)
   +(vec[2][k].second-vec[3][l].second)*(vec[2][k].second-vec[3][l].second);

   long long d4 = (vec[0][i].first-vec[2][k].first)*(vec[0][i].first-vec[2][k].first)
   +(vec[0][i].second-vec[2][k].second)*(vec[0][i].second-vec[2][k].second);

   long long d5 = (vec[0][i].first-vec[3][l].first)*(vec[0][i].first-vec[3][l].first)
   +(vec[0][i].second-vec[3][l].second)*(vec[0][i].second-vec[3][l].second);

   long long d6 = (vec[3][l].first-vec[1][j].first)*(vec[3][l].first-vec[1][j].first)
   +(vec[3][l].second-vec[1][j].second)*(vec[3][l].second-vec[1][j].second);
//    cout<<i<<" " <<j<<" "<<k<<" "<<l<<endl;
//   cout<<d1<<" " <<d2<<" "<<d3<<" "<<d4<<" "<<d5<<" "<<d6<<endl;
//   cout<<vec[0][i].first<<" "<<vec[0][i].second<<endl;
//   cout<<vec[1][j].first<<" "<<vec[1][j].second<<endl;
//   cout<<vec[2][k].first<<" "<<vec[2][k].second<<endl;
//   cout<<vec[3][l].first<<" "<<vec[3][l].second<<endl;
   map<long long ,bool>temp;
   temp[d1]=1;
   temp[d2]=1;
   temp[d3]=1;
   temp[d4]=1;
   temp[d5]=1;
   temp[d6]=1;
   return temp.size()==2;
 }
 void check(){
   long long mn=1e9;
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
     for(int k=0;k<4;k++)
      for(int l=0;l<4;l++){
        if(vec[0][i]!=vec[1][j] && vec[1][j]!=vec[2][k] && vec[2][k]!=vec[3][l])
           if(vec[0][i]!=vec[2][k] && vec[0][i]!=vec[3][l] && vec[1][j]!=vec[3][l])
             if(square(i,j,k,l))
               mn=min(mn,1LL*i+j+k+l);
      }
  if(mn!=1e9) cout<<mn<<endl;
  else cout<<-1<<endl;
  for(int m=0;m<4;m++)
    vec[m].clear();
 }
 int main(){
  int n;
  cin >> n;
  n*=4;
  for(int i=0;i<n;i++){
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    vec[i%4].push_back({x,y});
    rotate90(x,y,a,b);
    vec[i%4].push_back({x,y});
    rotate90(x,y,a,b);
    vec[i%4].push_back({x,y});
    rotate90(x,y,a,b);
    vec[i%4].push_back({x,y});
    if((i)%4==3) check();

//    cout<<vec[i][0].first<<" "<<vec[i][0].second<<endl;
//    cout<<vec[i][1].first<<" "<<vec[i][1].second<<endl;
//    cout<<vec[i][2].first<<" "<<vec[i][2].second<<endl;
//    cout<<vec[i][3].first<<" "<<vec[i][3].second<<endl;
  }

}
