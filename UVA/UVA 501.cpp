#include <cstdio>
#include <set>
using namespace std;
int Case, M, N;
int A[30010], U[30010];
int main()
{
    freopen("input.txt","rt",stdin);
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &M, &N);
        for (int i = 0; i < M; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i < N; ++i)
            scanf("%d", &U[i]);

        multiset<int> Box;
        for (int i = 0, u = 0, a = 0; u < N; ++u, ++i)
        {
            while (a < U[u] && a < N)
                Box.insert(A[a++]);

            auto iter = Box.cbegin();
            for (int j = 0; j < i; ++j)
                ++iter;
            printf("%d\n", *iter);
        }
        if (Case) printf("\n");
    }
    return 0;
}
