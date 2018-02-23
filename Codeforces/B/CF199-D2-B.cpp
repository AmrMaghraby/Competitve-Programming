 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int x1,y,R1[2],x2,y2,R2[5];
 map<int,bool>mp;
 bool inter(int i,int j){
   if(((x1-x2)*(x1-x2)+(y-y2)*(y-y2))<=(R1[i]+R2[j])*(R1[i]+R2[j])){
        //cout<<"y"<<endl;
        return true;
   }
   return false;
 }
 bool conc(int i,int j){
   if(((x1-x2)*(x1-x2)+(y-y2)*(y-y2))<=(R1[i]-R2[j])*(R1[i]-R2[j])){
        ///cout<<"r"<<endl;
        return true;
   }
   return false;
 }
 int main(){
  cin >> x1 >> y >> R1[0] >> R1[1] >> x2 >> y2 >> R2[2] >> R2[3];
  int ans=4;
  for(int i=0;i<2;i++)
   for(int j=2;j<4;j++)
    if(inter(i,j)&&!conc(i,j)){
      /// cout<<i<<" "<<j<<endl;
                mp[i]=1;
                mp[j]=1;
    }
  cout<<4-mp.size();
 }
