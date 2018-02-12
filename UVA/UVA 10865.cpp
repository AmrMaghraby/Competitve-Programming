 #include <bits/stdc++.h>
 using namespace std;
 int n;
 pair<int,int>pa[200005];
 int main(){
 while(cin >> n && n){

     memset(pa,0,sizeof pa);
     for(int i=0;i<n;i++)
      cin >> pa[i].first >> pa[i].second;
     int mid = n/2;
     int s=0,o=0;
     for(int i=0;i<n;i++){
      if(pa[i].first>pa[mid].first && pa[i].second>pa[mid].second)
         s++;
      else if(pa[i].first<pa[mid].first && pa[i].second<pa[mid].second)
         s++;
      else if(pa[i].first<pa[mid].first && pa[i].second>pa[mid].second)
         o++;
      else if(pa[i].first>pa[mid].first && pa[i].second<pa[mid].second)
         o++;
     }
      cout<<s<<" "<<o<<endl;
   }
 }
