///WA solution
///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 vector<int>ans,ans3;

 long long cnt[1000003];
 short flag;
 long long ans2;
 int main(){
 int n;
 cin >> n;
 for (int i=0;i<n;i++){
   int a;
   cin >> a;
   cnt[a]++;
 }
 for(int i=1000002;i>=1;i--){
   if(cnt[i]%2==0&&cnt[i]!=0)
     ans.push_back(i);
   if(cnt[i]!=0)
       if(cnt[i-1]%2==1&&cnt[i]%2==1)
          cnt[i-1]+=1,cnt[i]--;
}
 sort(ans.begin(),ans.end());
 for(int i=0;i<ans.size();i++){
    if(ans[i]!=ans[i+1])
  while(cnt[ans[i]]>0&&cnt[ans[i]]-2>=0){
     ans3.push_back(ans[i]);
     cnt[ans[i]]-=2;
  }
 }
  sort(ans3.begin(),ans3.end());
 if(ans3.size()<2){
   cout<<0;
   return 0;
 }else
  for(int i=ans3.size()-1;i>=0;i--){
    if((i-1)<0)
      continue;
    ans2+=(1LL*ans3[i]*ans3[i-1]);
    i--;
  }
 cout<<ans2;
}
