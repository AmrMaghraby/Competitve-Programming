#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N;
char table[128][128];
vector<pii> Js;
inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < N && j < N;}
inline bool in(pii a){ return in(a.first, a.second);}
inline int f(pii a){ return int(table[a.first][a.second]);}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%c", &table[i][N]);
        for(int j = 0; j < N; j++){
            scanf("%c", &table[i][j]);
            if(table[i][j] == 'J') Js.push_back(pii(i,j));
        }
    }
    int ans = 0;
    for(int i = 0; i < Js.size(); i++)
        for(int j = i+1; j < Js.size(); j++){
            pii a = Js[i], b = Js[j];
            int di = b.first - a.first, dj = b.second - a.second;
            if(ans >= di*di+dj*dj) continue;
            pii c = pii(a.first - dj, a.second + di);
            pii d = pii(c.first + di, c.second + dj);
            if(in(c) && in(d) && ((f(c)+f(d) == int('J'+'*')) || (f(c)+f(d) == int('J'+'J')))){
                ans = di*di+dj*dj;
                //printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d) -> %d\n", a.first, a.second, b.first, b.second, c.first, c.second, d.first, d.second, ans);
                continue;
            }
            c = pii(a.first + dj, a.second - di);
            d = pii(c.first + di, c.second + dj);
            if(in(c) && in(d) && ((f(c)+f(d) == int('J'+'*')) || (f(c)+f(d) == int('J'+'J')))){
                ans = di*di+dj*dj;
                //printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d) -> %d\n", a.first, a.second, b.first, b.second, c.first, c.second, d.first, d.second, ans);
                continue;
            }
        }
    printf("%d\n", ans);
    return 0;
}
