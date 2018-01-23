 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int Size;
 string str;
 int m[705];
 const int MOD = 1000000007;
 long long mem[705][705][3][3];
 long long DP(int l,int r,int cl,int cr){
   long long ret = 0;
    if(mem[l][r][cl][cr]!=-1)
     return mem[l][r][cl][cr];
  if(l>r) return cl==0 && cr==0;

  int k=m[l];
  if(k==r){
     if(!((cl == 0) ^ (cr == 0)))return 0;
   for(int i=0;i<=2;i++)
     for(int j=0;j<=2;j++)
       if((cl!=i||cl==0)&&(cr!=j||cr==0))
           ret=(ret + DP(l+1,r-1,i,j))%MOD;
  }else {
   for(int i=0;i<=2;i++)
     for(int j=0;j<=2;j++)
       if(i==0||j==0||i!=j)
         //ret = (ret +(long long)(DP(l,k,cl,i)*DP(k+1,r,j,cr)))%MOD;
 ret = (ret + (long long)DP(l, k, cl, i) * DP(k + 1, r, j, cr)) % MOD;
  }
  return mem[l][r][cl][cr]=ret;
 }
 int main(){
  stack<int> st;
  cin >> str;
  memset(mem,-1,sizeof mem);
  for(int i=0;i<str.size();i++)
    if(str[i]=='(')
       st.push(i);
    else {
            int k = st.top();
            m[k]=i;
            st.pop();
    }
  long long ans=0;
  int N2 = str.size()-1;
  for(int i=0;i<=2;i++)
  for(int j=0;j<=2;j++)
      ans = (ans+DP(0,N2,i,j))%MOD;
   cout<<ans;
 }
