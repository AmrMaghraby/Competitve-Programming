///IN THE NAME PF ALLAH
#include<bits/stdc++.h>
using namespace std;
bool Primes[100005];
vector<int>X;
vector< pair<int,int> >Y;
int Arr[100005],Arr2[300005];
int main(){
 for(int i=2;i<=100000;i++)
   Primes[i]=1;
 for(int i=2;i<=100000;i++)
   if(Primes[i])
     for(int j=i+i;j<=100000;j+=i)
         Primes[j]=0;
 for(int i=0;i<=100001;i++)
    if(Primes[i]) X.push_back(i);
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++){
    scanf("%d",&Arr[i]);
    Arr2[i]=Arr[i];
 }
 sort(Arr2,Arr2+n);
 bool f=0;
 for(int i=0;i<n;i++){
    f=0;
    long long Temp = i;
    while(Temp<n&&Arr[Temp]!=Arr2[Temp]){
     if(Temp<0){
        cout<<Temp;
        return 0;
     }
     int index = lower_bound(Arr2,Arr2+n,Arr[Temp])-Arr2;
     int T = index-Temp+1;
     if(T<0){cout<<"ddddddddddddd"<<" "<<T<<endl; T*=-1;}
     int index2 = lower_bound(X.begin(),X.end(),T)-X.begin();
     if(X[index2]>(index-Temp+1)||index2>=X.size())
         index2--;
     if(Temp+X[index2]-1>n)
        return 0;
     swap(Arr[Temp],Arr[Temp+X[index2]-1]);
     Y.push_back({Temp+1,Temp+X[index2]});
     int last = Temp;
     Temp=Temp+X[index2]-1;

     if(Temp<0){
        cout<<last<<" "<<Temp<<" "<<index2<<" "<<X[index2]<<" "<<index<<" "<<T;
        return 0;
     }
     f=1;
    }
    if(f)i--;
 }
 cout<<Y.size()<<endl;
 for(int i=0;i<Y.size();i++)
    cout<<Y[i].first<<" "<<Y[i].second<<endl;;
}

