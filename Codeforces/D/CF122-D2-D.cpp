 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
  int n,m,lst=-1;
  cin >> n >> m;
  string str;
  cin >> str;
  for(int i=0;i<str.size()&&m;i++){
     if(str[i]=='4'&&str[i+1]=='4'){
        for(;i<str.size()&&m;)
           if(str[i]=='4'){
              i++;
              continue;
           } else if(str[i]=='7' && (i-1)%2==1){
             lst = i-1;
             break;
           } else if(str[i]=='7')
             str[i]='4',m--,i++;
            else break;
        } else if(str[i]=='4'&&str[i+1]=='7'&&i%2==1)
                        str[i]='7',m--,i--;
          else if(str[i]=='4'&&str[i+1]=='7'&&i%2==0)
                        str[i+1]='4',m--,i--;
       if(lst!=-1)
          break;
   }
   if(m && lst!=-1){
        str[lst]='7',m--;
        if(m%2==0)
           cout<<str;
        else {
            str[lst]='4';
            cout<<str;
        }
   }
   else if(lst==-1||!m)
    cout<<str;
 }
