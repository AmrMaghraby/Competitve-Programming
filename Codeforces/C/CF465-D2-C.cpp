///in the name of allah
#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,p;
 cin >> n >> p;
 string str;
 cin >> str;
 for(int i=str.size()-1;i>=0;i--){
  for(char j='a';j-'a'<p;j++){
  if(j<=str[i]) continue;
  if(j != str[i-1] && j !=str[i-2]){
     str[i]=j;
     int z=0;
     char T;
     if(str[i]!='a'&&str[i-1]!='a')
        T='a';
     else if(str[i]!='b'&&str[i-1]!='b')
        T='b';
     else if(str[i]!='c'&&str[i-1]!='c')
        T='c';
     bool f=0;
     for(int k=i+1;k<n;){
        if(str.size()>=2&&T!=str[k-1]&&T!=str[k-2])
          str[k]=T,k++;
        else if(str.size()==1&&T!=str[k-1])
          str[k]=T,k++;
        if(T=='c'||f==0)
          T='a';
        else T++;
        f=1;
     }
     cout<<str;
     return 0;
   }
  }
 }
 cout<<"NO";
}
/*.
11 3
abcabcabcab
*/
