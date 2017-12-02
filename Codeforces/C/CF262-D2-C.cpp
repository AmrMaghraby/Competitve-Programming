///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int m,n,mn=1e9,cnt;
 vector<int>vec;
 long long Sum=0;
 int main(){
  cin >> m;
  for(int i=0;i<m;i++){
   int a;
   cin >> a;
   mn=min(mn,a);
  }
 cin >> n;
 for(int i=0;i<n;i++){
  int a;
  cin >> a;
  vec.push_back(a);
 }
 sort(vec.begin(),vec.end());
 for(int i=vec.size()-1;i>=0;i--){
    Sum+=vec[i];
    cnt++;
    if(cnt==mn){
     cnt=0;
     i-=2;
    }
 }
 cout<<Sum;
}



