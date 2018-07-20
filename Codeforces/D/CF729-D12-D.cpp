 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 using namespace std;
 int main(){
  int n,a,b,k,cnt=0,ans=0,v=0;
  vector<int>vec;
  cin >> n >> a >> b >> k;
  string str;
  cin >> str;
  for(int i=0;i<str.size();i++){
       if(str[i]=='0') {
         cnt++;
         if(cnt!=0&&cnt%b==0)
            ans++;
       }else cnt=0;
  }
  cnt=0;
  for(int i=0;i<str.size();i++){
       if(str[i]=='0') cnt++;
       else cnt=0;
       if(cnt!=0&&cnt%b==0){
         vec.push_back(i+1);
         v++;
         if(ans-v<a) break;
       }
  }
  cout<<vec.size()<<endl;
  for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
 }
