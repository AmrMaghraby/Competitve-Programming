
  ///IN THE NAME OF ALLAH
  #include<bits/stdc++.h>
  using namespace std;
  map<long long,int>mp1,mp2;
  long long Arr[200005];
  int main(){
   int n,k;
   cin >> n >> k;
   for(int i=0;i<n;i++){
     cin >> Arr[i];
     mp2[Arr[i]]++;
   }
   long long ans=0;
   for(int i=0;i<n;i++){
     mp2[Arr[i]]--;
     if(Arr[i]%k==0)
       ans += (1LL*(mp1[Arr[i]/k])*(mp2[Arr[i]*k]));
     mp1[Arr[i]]++;
   }
   cout<<ans;
  }



