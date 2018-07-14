///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 map<int,int>mp;
 pair<int,int> Arr[6000];
 int main(){
  int Tc;
  cin >> Tc;
  while(Tc--){
    vector<int> adj;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
       cin >> Arr[i].first >> Arr[i].second;
    sort(Arr,Arr+n);
    bool f=0;
    for(int i=0;i<n;i++){
        f=0;
        for(int j=0;j<adj.size();j++){
            if(adj[j]<=Arr[i].second){
                  adj[j]=Arr[i].second;
                  f=1;
                  break;
            }
        }
     if(!f) adj.push_back(Arr[i].second);
    }

    cout<<adj.size()<<endl;
  }
 }
