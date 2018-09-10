 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 using namespace std;
 int n;
 int vec[1005];
 map<int,int>mp;
 int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
       int a;
       scanf("%d",&a);
       vec[i]=a;
       mp[a]++;
  }
  sort(vec,vec+n);
  int ans=2;
  ans=max(ans,mp[0]);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)if(i!=j){
     int cnt=2;
     int Before = vec[i] , After = vec[j];
     if(Before == 0 && After == 0) continue;
     if (i && vec[i] == vec[i-1]) continue;
     int Test =0;
     map<int,int>mp2;
     mp2[vec[i]]++;
     mp2[vec[j]]++;
     while(true){
        Test = Before + After;
        if(++mp2[Test]>mp[Test]) break;
        Before = After;
        After = Test;
        cnt++;
     }
     ans=max(cnt,ans);
    }
   }
   cout<<ans;
 }

