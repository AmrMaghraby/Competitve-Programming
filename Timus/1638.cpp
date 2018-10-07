/*

Idea :  just imagine.
when you place books on the shelf, the books are facing inwards, which means, the first page is on the right and the last page is on the left.

*/
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
  int Volume,cover,start,endd;
  cin >> Volume >> cover >> start >> endd;
  if(start<endd){
      int ans=0;
      if(start==endd){
        ans+=Volume;
        cout<<ans;
        return 0;
      }
      for(int i=start;i+1<endd;i++)
        ans+=(2*cover+Volume);
      ans+=2*cover;
      cout<<ans;
  }else{
      int ans=0;
      if(start==endd){
        ans+=Volume;
        cout<<ans;
        return 0;
      }
      for(int i=start;i>endd;i--)
        ans+=(2*cover+Volume);
      ans+=Volume;
      cout<<ans;
  }
 }

