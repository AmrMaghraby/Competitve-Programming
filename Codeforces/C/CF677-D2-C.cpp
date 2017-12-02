 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 map<char,int>mp;
 vector<int> vec;
 long long sz=0;
 int main(){
 mp['0']=0;
 mp['1']=1;
 mp['2']=2;
 mp['3']=3;
 mp['4']=4;
 mp['5']=5;
 mp['6']=6;
 mp['7']=7;
 mp['8']=8;
 mp['9']=9;
 long long cnt=10;
 for(char b='A';b<='Z';b++)
      mp[b]=cnt++;
 for(char a='a';a<='z';a++)
      mp[a]=cnt++;

 mp['-']=cnt++;
 mp['_']=cnt++;
 cnt=0;
 string str;
 cin >> str;
 for(int i=0;i<str.size();i++)
  vec.push_back(mp[str[i]]);
 long long ans=1;
 for(int i=0;i<vec.size();i++){
    for(int j=0;j<6;j++)
       if(((1<<j)&vec[i])==0)
         ans=(ans*3)%1000000007;
 }
cout<< ans ;






}




