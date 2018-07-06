#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX = 200200;
int n, arr[MAX], cnt;
vector<int> adj[MAX];
bool vis[MAX];
void dfs(int cur, int par, int& c){
    if(vis[cur]){
        c = cur;
        return;
    }
    vis[cur] = 1;
    int sz = adj[cur].size();
    for(int i = 0; i < sz; i++) if(adj[cur][i] !=  par)
        dfs(adj[cur][i], cur, c);
}
int main()
{
    scanf("%d", &n);
    int root = -1;
    for(int i = 1; i <= n; i++){
        scanf("%d", arr + i);
        adj[arr[i]].push_back(i);
        adj[i].push_back(arr[i]);
        if(i == arr[i]) root = i;
    }
    for(int i = 1; i <= n; i++) if(!vis[i]){
        int a;
        dfs(i, 0, a);
        if(root != -1){
            if(root != a)
                arr[a] = root, cnt++;
        }
        else{
            root = a;
            arr[a] = root;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    return 0;
}
