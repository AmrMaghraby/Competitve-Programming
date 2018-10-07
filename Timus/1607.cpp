 /* Naiive but tricky */
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
  int N,Cn,D,CD;
  int T;
  cin >> N >> Cn >> D >> CD;
  if(N>=D){
    cout<<N;
    return 0;
  }
  while(N<D){
    if(N+Cn<=D){
        N=N+Cn;
    } else{
         N = D;
         break;
    }
    D-=CD;
  }
   cout<<N;
 }

