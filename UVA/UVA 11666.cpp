 /*
 ln(n/1-x) = L
(n/(1-x)) = exp(L)
n = (1-x) * exp(L)
n/exp(L) = 1-x
x = 1 - n/exp(L)
 */
///IN THE NAME OF ALLAH
#include <stdio.h>
#include <math.h>
int main() {
    double n, ans;
    while(scanf("%lf", &n) == 1 && n) {
        int L = (int)floor(log(n));
        ans = 1 -  n/exp(L);
        if(fabs(ans) >= 1.0) {
            L++;
            ans = 1 - n/exp(L);
        }
        printf("%d %.8lf\n", L, ans);
    }
    return 0;
}


