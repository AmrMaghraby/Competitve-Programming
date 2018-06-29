#include<bits/stdc++.h>
using namespace std;
// -__________-
const int MAXN = 5002 , NP = 1e9;
int Add[MAXN] , MyResult[MAXN] , MyCheck[MAXN] ;
bool check(int n  , vector<pair< int , pair< int , pair< int , int > > > > A){
    for(int i = 0 ;i < A.size() ;i ++){
        int t = A[i].first , s = A[i].second.first , e = A[i].second.second.first , v = A[i].second.second.second;
        if(t == 1){
            for(int i = s - 1; i <= e - 1; i ++){
                MyCheck[i] += v;
            }
        }
        else {
            int mx = MyCheck[s - 1];
            for(int i = s - 1 ; i <= e - 1; i ++)
                mx = max(mx , MyCheck[i]);
            if(mx != v)return 0;
        }
    }
    return 1;
}
int main()
{
    int t , n , m , s , e , v;
    vector< pair< int , pair< int , pair< int , int > > > > A;
    scanf("%d%d" ,&n , &m);
    for(int i = 0 ;i < n ;i ++)
        MyCheck[i] = MyResult[i] = NP;
    while(m --){
        scanf("%d%d%d%d" ,&t , &s , &e , &v);
        A.push_back(make_pair(t , make_pair(s , make_pair(e , v))));
        if(t == 1){
            for(int i = s - 1; i <= e - 1; i ++)
                Add[i] += v;
        }
        else {
            for(int i = s - 1; i <= e - 1 ;i ++)
                MyResult[i] = min(MyResult[i] , v - Add[i]);
        }
    }
    for(int i = 0; i < n ;i ++)
        MyCheck[i] = MyResult[i];
    if(check(n , A)){
        printf("YES\n");
        for(int i = 0 ;i < n ;i ++){
            if(i)printf(" ");
           printf("%d", MyResult[i]);
        }
        printf("\n");
    }
    else
        printf("NO\n");
}
