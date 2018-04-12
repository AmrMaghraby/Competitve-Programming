#include <bits/stdc++.h>
using namespace std;
int n,nedg;
long long tom;
vector<vector<pair<int, long long>>>edges;
long long DP[5001][5001];
long long cost(int cur,int nodes_left){
    if (cur==n-1) {
        return nodes_left==0?0:1e11;
    }
    if (nodes_left==0) {
        return 1e11;
    }
    if (DP[cur][nodes_left]!=-1) {
        return DP[cur][nodes_left];
    }
    long long sol=1e11;
    for (int i=0; i<edges[cur].size(); i++) {
        sol = min(sol,cost(edges[cur][i].first, nodes_left-1)+edges[cur][i].second);
    }
    return  DP[cur][nodes_left]=sol;
}
void outting(int cur,int nodes_left){
    cout<<cur+1<<" ";
    if (cur==n-1) {
        return;
    }
    for (int i=0; i<edges[cur].size(); i++) {
        if (cost(edges[cur][i].first, nodes_left-1)+edges[cur][i].second==DP[cur][nodes_left]) {
            outting(edges[cur][i].first, nodes_left-1);
            return;
        }
    }
}
int main(){
    memset(DP, -1, sizeof(DP));
    cin>>n>>nedg>>tom;
    edges.assign(n, vector<pair<int, long long>>());
    for (int i=0; i<nedg; i++) {
        int s,e,c;
        cin>>s>>e>>c;
        edges[s-1].push_back(make_pair(e-1,c));
    }
    for (int i=n; i>=0; i--) {
        if (cost(0, i-1)<=tom) {
            cout<<i<<endl;
            outting(0,i-1);
            cout<<endl;
            return 0;
        }
    }
    return 0;
}

