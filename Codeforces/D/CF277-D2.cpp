 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 long long n,m;
 int Arr[100005];
 long long Sum[100005];
 long long getSum(long long l,long long r){
   r=min(r,n-1);
   return Sum[r]-Sum[l];
 }
 int main(){
  cin >> n;
  for(int i=0;i<n;i++) cin >> Arr[i];
  sort(Arr,Arr+n);
  reverse(Arr,Arr+n);
  Sum[0]=Arr[0];
  for(int i=1;i<n;i++)
    Sum[i]=Sum[i-1]+Arr[i];
  long long ans1=0;
  for(int i=1;i<n;i++)
     ans1+=1LL*Arr[i]*i;
  int q;
  cin >> q;
  while(q--){
   int k;
   cin >> k;
   if(k==1){
     cout<<ans1<<endl;
     continue;
   }
   long long ans2=0,sz=1,t=0,i=0;
   while(i<n){
      t++;
      sz*=k;
      ans2+=getSum(i,sz+i)*t;
      i+=sz;
   }
   cout<<ans2<<" ";
  }
 }
