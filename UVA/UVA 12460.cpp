
///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int n,m,h[100005],pa[100005];
 map<string,int>mp;
 void Make_SET(int i){
        pa[i]=i;
        h[i]=1;
 }
 int find(int x){
  if(x==pa[x])return x;
   return pa[x]=find(pa[x]);
 }
 void Union(int x,int y){
  if(x==y)return;
  if(h[x]>=h[y]){
        h[x]+=h[y];
        pa[y]=x;
  } else {
    h[y]+=h[x];
    pa[x]=y;
  }
}
 bool check(string str, string str2){
   if(str.size()==str2.size()){
     int f=0;
     for(int i=0;i<str.size();i++)
       if(str[i]!=str2[i])
            f++;
     return f<=1;
   }
  return false;
 }
 int main(){
     memset(pa,0,sizeof pa);
     memset(h,0,sizeof h);
     mp.clear();
     int id=1;
     string str;
     while(true){
        cin >> str;
        if(str=="--") break;
      Make_SET(id);
      mp[str]=id++;
      map<string,int>::iterator itr;
      for(itr = mp.begin();itr!=mp.end();itr++)
          if(itr->first!=str && check(itr->first,str))
            Union(find(mp[itr->first]),find(mp[str]));
     }
     string str1,str2;
     while(cin >> str1 >> str2){
      int a,b;
      a = mp[str1];
      b = mp[str2];
      if(find(a)==find(b))
           cout<<"Yes"<<endl;
      else
           cout<<"No"<<endl;
     }
  }

