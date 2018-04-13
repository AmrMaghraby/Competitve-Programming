#include<bits/stdc++.h>

using namespace std;

#define MAX 100005

int arr[MAX],len[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    fill(len+1,len+n+1,1e9);
    len[0]=-1e9;
    int res=0;
    while(n--)
    {
        int x;
        cin>>x;
        int idx=lower_bound(len,len+res+1,x)-len;
        res=max(res,idx);
        len[idx]=x;
    }
    cout<<res<<endl;
    return 0;
}
