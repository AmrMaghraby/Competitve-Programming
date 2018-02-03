    ///IN THE NAME OF ALLAH
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long>Vec,Primes;
    long long n,L;
    map<long long,bool>mp;
    void getDivisors(){
      long long Limit = ceil(sqrt(n));
      for(int i=1;i<=Limit;i++)
        if(n%i==0 &&i!=1 && i!=n){
            if(mp.count(i))
               continue;
             Vec.push_back(i);
             mp[i]=1;
            if(mp.count(n/i))
               continue;
             Vec.push_back(n/i);
             mp[n/i]=1;
        }
    }
    void PRIME(){
     for(int i=0;i<Vec.size();i++){
         long long limit = ceil(sqrt(Vec[i]));
         bool f=0;
         for(int j=2;j<=limit;j++)
          if(Vec[i]!=j && Vec[i]%j==0)
            f=1;
         if(f==0) Primes.push_back(Vec[i]);
         f=1;
     }
    }
    int main(){
     cin >> n;
     getDivisors();
     PRIME();
     sort(Primes.begin(),Primes.end());
     if(Vec.size()==0){
         cout<<"1"<<endl<<"0";
         return 0;
     }
     else if(Primes.size()==mp.size()){
         cout<<"2"<<endl;
         return 0;
     } else cout<<"1"<<endl;
     if((Primes.size()>=2))
        cout<<(1LL*Primes[0]*1LL*Primes[1])<<endl;
     else cout<<(1LL*Primes[0]*Primes[0])<<endl;

//     map<long long ,bool>::iterator itr;
//     for( itr = mp.begin();itr!=mp.end();itr++)
//        cout<<(itr->first)<<endl;
//     cout<<"+++++++++++++++++++++++++++++"<<endl;
//     for(int i=0;i<Primes.size();i++)
//         cout<<Primes[i]<<endl;


    }
