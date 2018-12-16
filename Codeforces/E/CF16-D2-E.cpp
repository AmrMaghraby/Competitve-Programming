#include <bits/stdc++.h>
using namespace std;
int n , t ;
int vis[1<<18] ;
double dp[1<<18] , a[18][18] ;
double solve(int mask){
    if(mask == (1<<n)-1)return 1.0 ;
    if(vis[mask])return dp[mask] ;
    vis[mask] = true ;
    double ret = 0.0 ;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ;j < n ; j++){
            if(mask&(1<<i) && !(mask&(1<<j))){
                ret += a[i][j] * solve(mask|(1<<j)) ;
            }
        }
    }
    int c = __builtin_popcount(mask) ;
    ret = ret*2.0/c/(c+1) ;
    return dp[mask] = ret ;
}
int main (){
    cin >> n ;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ;j < n ; j++){
            cin >> a[i][j] ;
        }
    }
    for(int i = 0 ;i < n;i++){
        printf("%.10lf ",solve(1<<i));
    }
    return 0 ;
}
