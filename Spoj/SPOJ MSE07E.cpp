///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int X[1000005],Y[1000005],Z[1000005],n;
 long long getSum(long long m){
   long long Sum=0;
   for(int i=0;i<n;i++){
     if(m>=Y[i])
       Sum+=((Y[i]-X[i])/Z[i]+1);
     else if(m>=X[i])
       Sum+=((m-X[i])/Z[i]+1);
   }
   return Sum;
 }
 int main(){
    string str="";
  while(getline(cin,str)){
    n=0;
    memset(X,0,sizeof X);
    memset(Y,0,sizeof Y);
    memset(Z,0,sizeof Z);
    long  long res=0;
    istringstream iss (str);
    int a;
    iss >> a;
    X[n]=a;
    iss >> a;
    Y[n]=a;
    iss >> a;
    Z[n]=a;
    res ^= ((Y[n]-X[n])/Z[n]+1);
    n++;
    while(getline(cin,str)){
        if(str=="") break;
        istringstream iss (str);
        int a;
        iss >> a;
        X[n]=a;
        iss >> a;
        Y[n]=a;
        iss >> a;
        Z[n]=a;
        res ^= ((Y[n]-X[n])/Z[n]+1);
        n++;
        str="";
    }
    if(res==0){
        cout<<"no corruption"<<endl;
        continue;
    }
    long long L=0,H=10000000;
    while(H-L>=1){
        long long m = 1LL*(H+L)/2;
        if(getSum(m)%2==0)
           L=m+1;
        else
           H=m;
    }
    int cnt = 0;
	for(int i=0; i<n; i++){
		if(X[i] <= L && L <= Y[i] && (L - X[i])%Z[i] == 0){
			cnt++;
		}
	}
    cout<<L<<" "<<cnt<<endl;

  }
 }

