#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > Answer;
int main()
{
    int k;
    cin>>k;
    if(!(k%2)){
        cout<<"NO\n";return 0;
    }
    cout<<"YES\n";
    cout<<((k-1)*2+1)*2<<" ";
    for(int i=2;i<=k;i++){
        Answer.push_back(make_pair(1,i));
    }
    for(int i=k+1;i<k*2;i++){
        for(int j=2;j<=k;j++){
            Answer.push_back(make_pair(i,j));
        }
    }
    for(int i=k+1;i<k*2;i+=2){
        Answer.push_back(make_pair(i,i+1));
    }
    cout<<Answer.size()*2+1<<"\n";
    for(int i=0;i<Answer.size();i++){
        cout<<Answer[i].first<<" "<<Answer[i].second<<"\n";
    }
    for(int i=0;i<Answer.size();i++){
        cout<<Answer[i].first+(k*2)-1<<" "<<Answer[i].second+k*2-1<<"\n";
    }
    cout<<1<<" "<<1+2*k-1<<"\n";
    return 0;
}
