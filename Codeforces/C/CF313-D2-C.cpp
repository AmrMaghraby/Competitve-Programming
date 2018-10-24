#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n , m , x = 0;
    long long ans = 0;
    scanf("%d" ,&n) , m = n;
    vector<int> A(n);
    for(int i = 0 ;i < n ;i ++)
        scanf("%d" ,&A[i]);
    sort(A.begin() , A.end());
    reverse(A.begin() , A.end());
    while(n){
        for(int i = 0 ;i < n ;i ++)
            ans += A[i];
        n /= 4;
    }
    printf("%I64d\n" , ans);

}
