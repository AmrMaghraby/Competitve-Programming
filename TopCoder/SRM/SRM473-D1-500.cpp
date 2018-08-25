 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 const int mod = 1000000007;
 bool used[1 << 20];
 int cnt[1 << 20];
 int main(){
 long long places,n,a,b,c;
 cin >>places>>n>>a>>b>>c;
 if(places%2!=0)
 {
     cout<<0;
     return 0;
 }
 for(long long  cn=0;cn<n;cn++){
   long long t = ((long long)cn * (long long)cn*(long long)a+(long long)cn*(long long)b+c)%places;
   if(used[t])
      cnt[t]++;
   else used[t]=1;
 // cout<<cn<<" "<<(((long long)a*cn*cn+(long long)b*cn+c)%places)<<endl;
 }
 int temp=0;
 for(int i=0;i<2*places;i++){
    temp+=cnt[i%places];
    cnt[i%places]=0;
    if(!used[i%places]&&temp){
          temp--;
          used[i%places]=1;
    }
 }
 long long half = places/2;
 long long res=0;
 for(int i=0;i<half;i++)
   if ( used[i] && used[(i + half) % places])
      res += n - 2;
 cout<<res;
}
/*

1000000
100000
0
500000
0



100000
100000
0
0
987654

40742
6139
472789
186244
867370

105446
80148
125598
487561
330543

1000000
100000
123
456
789

*/
