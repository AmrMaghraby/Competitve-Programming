#include<bits/stdc++.h>
using namespace std;
vector< pair<int,char> >vec;
map<char,int>mp;
map<char,bool>mp2;
int temp[27],k;
string str,Builder;
int main(){
 cin >> str >> k;
 for(int i=0;i<str.size();i++)
   temp[str[i]-'a']++;
 for(int i=0;i<26;i++)
  if(temp[i]!=0)
   vec.push_back({temp[i],i+'a'});
 sort(vec.begin(),vec.end());
 for(int i=0;i<vec.size();i++)
  if(vec[i].first!=0){
     if(k>0){
       int T=k;
       //cout<<vec[i].first<<" "<<vec[i].second<<" "<<k<<" Before ";
       k-=vec[i].first;
       vec[i].first=(vec[i].first-T)>0?(vec[i].first-T):0;

       //cout<<vec[i].first<<" "<<vec[i].second<<" "<<k<<" after "<<endl;

     }
  }
 for(int i=0;i<vec.size();i++)
    mp[vec[i].second]=vec[i].first;
 for(int i=0;i<str.size();i++){
   if(mp[str[i]]>0){
     mp2[str[i]]=1;
     Builder.push_back(str[i]);
     mp[str[i]]--;
   }
 }
 cout<<mp2.size()<<endl;
 cout<<Builder;
}
