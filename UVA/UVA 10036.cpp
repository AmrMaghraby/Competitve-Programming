///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int y,x;
 int Arr[30000];
 int mem[10005][200];
 int dp(int i,int sum){
  if(i==x) return sum==0?1:0;
  if(mem[i][sum]!=-1)
    return mem[i][sum];
  int r = dp(i+1,((sum+Arr[i])%y+y)%y);
  r|=dp(i+1,((sum-Arr[i])%y+y)%y);
  return r;
 }
 int main(){
    int Tc;
    scanf("%d",&Tc);
    while(Tc--){
        memset(mem,-1,sizeof mem);
        scanf("%d %d",&x,&y);
        for(int i=0;i<x;i++) scanf("%d",&Arr[i]);
      if(dp(1,(Arr[0]+y)%y))
         printf("Divisible\n");
      else
         printf("Not divisible\n");
    }
}
