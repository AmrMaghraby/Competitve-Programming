 ///IN THE NAME OF ALLAH
 #include <bits/stdc++.h>
 using namespace std;
 int main(){
 int tc;
 cin >> tc;
  while(tc--){
    long long unsigned a,b,c,d,mid,Sum=1;
    scanf("%llu %llu %llu %llu",&a,&b,&c,&d);
    priority_queue < long long , vector<int>, less<int> > left;
    priority_queue < long long , vector<int>, greater<int> > right;
    left.push(1);
    for(int i=2;i<=d;i++){
       mid = left.top();
       long long unsigned N = ((a*mid)+(b*i)+c);
       if(N>=1000000007)  N%=1000000007;
       Sum+=N;
       if(left.size()>right.size()){
            if(N<left.top()){
             left.pop();
             left.push(N);
             right.push(mid);
            }else right.push(N);
       } else {
            if(N>right.top()){
              long long unsigned Q = right.top();
              right.pop();
              left.push(Q);
              right.push(N);
            }else left.push(N);
       }
      }
   cout<<Sum<<endl;
 }
}
