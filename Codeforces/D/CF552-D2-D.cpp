#include <bits/stdtr1c++.h>

using namespace std;
pair<int,int> arr[2001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    long long ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if((arr[j].second-arr[i].second)*(arr[k].first-arr[i].first)!=(arr[k].second-arr[i].second)*(arr[j].first-arr[i].first))
                    ans+=(long long)1;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
