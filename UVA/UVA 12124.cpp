#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
using namespace std;
int b;
const int maxn = 1000 + 1;
struct Component{
    int price;
    int quality;
};
vector<Component> comp[maxn];
map<string,int> id;
int cnt;
int GetCompId(string type){
    if(!id.count(type)){
        id[type] = cnt;
        cnt ++;
    }
    return id[type];
}
bool isOK(int mid){
    int i,j,sum=0;
    for(i = 0;i < cnt;i++){
        int cheapest = b + 1;
        int size = comp[i].size();
        for(j = 0;j < size;j++){
            if(comp[i][j].quality >= mid){
                if(comp[i][j].price < cheapest){
                    cheapest = comp[i][j].price;
                }
            }
        }
        if(cheapest == b+1){
            return false;
        }
        sum += cheapest;
        if(sum > b){
            return false;
        }
    }
    return true;
}
int main(){
    int T,i,j,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&b);
        cnt = 0;
        for(i = 0;i < n;i++){
            comp[i].clear();
        }
        id.clear();
        int maxq = 0;
        for(i = 0;i < n;i++){
            char type[30],name[30];
            int price,quality;
            scanf("%s %s %d %d",type,name,&price,&quality);
            if(quality > maxq){
                maxq = quality;
            }
            int id = GetCompId(type);
            comp[id].push_back(Component{price,quality});
        }
        int L = 0,R = maxq;
        while(L < R){
            int mid = L+(R - L + 1) / 2;
            if(isOK(mid)){
                L = mid;
            }
            else{
                R = mid - 1;
            }
        }
        printf("%d\n",L);
    }
    return 0;
}
