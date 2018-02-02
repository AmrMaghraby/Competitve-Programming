    ///IN THE NAME OF ALLAH
    #include<bits/stdc++.h>
    using namespace std;
    int Arr[200005];
    map<int,int>mp;
    int main(){
      int n,k;
      long long ans=0;
      cin >> n >> k;
      for(int i=0;i<n;i++)
          cin >> Arr[i];
      sort(Arr,Arr+n);
      for(int i=0;i<n;i++){
        if(Arr[i]%k==0&&mp.count(Arr[i]/k))
            continue;
        ans++;
        mp[Arr[i]]=1;
      }
     cout<<ans<<endl;

    }
