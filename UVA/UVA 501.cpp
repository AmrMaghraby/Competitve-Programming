#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int A[30010];
int main()
{
   // freopen("input.txt","rt",stdin);
    int Case, M, N, tmp;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &M, &N);
        for (int i = 0; i < M; ++i)
            scanf("%d", &A[i]);

        vector<int> Box;
        int U, a = 0, i = 0; // a is index of A
        while (N--) {
            scanf("%d", &U);
            while (a < U) { // lower_bound回傳一個iterator指向Box裡面第一個>=A[a]的元素
                auto iter = lower_bound(Box.begin(), Box.end(), A[a]);
                Box.insert(iter, A[a++]);
            }
            printf("%d\n", Box[i++]);
        }
        if (Case) printf("\n");
    }
    return 0;
}
