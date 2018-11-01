 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 const int maxN = 100001;
 const ll inf  = 2*1e9;
 ll A[maxN], N, Q;
 class Segment_Tree {
 private:
    ll it_sum[4*maxN],it_PowerdSum[4*maxN],lazy[4*maxN];
 public:
    void par_update(int x) {
        it_sum[x] = it_sum[2*x] + it_sum[2*x+1];
        it_PowerdSum[x] = it_PowerdSum[2*x] + it_PowerdSum[2*x+1];
    }
    void Build(int x, int L, int R) {
        if (L == R){
            it_sum[x] = A[L];
            it_PowerdSum[x] = A[L]*A[L];
        }else {
            int mid = (L + R) >> 1;
            Build(2*x, L, mid);
            Build(2*x+1, mid+1, R);
            par_update(x);
        }
    }
    void lazy_update(int x) {
        if (!lazy[x]) return;

        lazy[2*x] += lazy[x];
        it_sum[2*x] += lazy[x];

        lazy[2*x+1] += lazy[x];
        it_sum[2*x+1] += lazy[x];

        lazy[x] = 0;
    }
    void Update1(int x, int L, int R, int u, int v, ll val) {
        if (L > v || R < u) return;
        if (L >= u && R <= v){
            lazy[x] += val;
            it_PowerdSum[x] = it_PowerdSum[x]+val*(R-L+1)+2*val*it_sum[x];
            it_sum[x] += val*(R - L + 1);
            return;
        }
        lazy_update(x);
        int mid = (L + R) >> 1;
        Update1(2*x, L, mid, u, v, val);
        Update1(2*x+1, mid+1, R, u, v, val);
        par_update(x);
    }
    void Update0(int x, int L, int R, int u, int v, ll val) {
        if (L > v || R < u) return;
        if (L >= u && R <= v) {
            lazy[x] = val;
            it_sum[x] = val*(R - L + 1);
            it_PowerdSum[x] = val*(R - L + 1);
            return;
        }
        lazy_update(x);
        int mid = (L + R) >> 1;
        Update0(2*x, L, mid, u, v, val);
        Update0(2*x+1, mid+1, R, u, v, val);
        par_update(x);
    }
    ll getSum(int x, int L, int R, int u, int v) {
        if (L > v || R < u) return 0;
        if (L >= u && R <= v) return it_PowerdSum[x];
        lazy_update(x);
        int mid = (L + R) >> 1;
        ll left = getSum(2*x, L, mid, u, v);
        ll right = getSum(2*x+1, mid+1, R, u, v);
        return left + right;
    }
 } IT;
 int main(){
    int Tc,id=1;
    cin >> Tc;
    while(Tc--){
        cout<<"Case "<<id++<<":"<<endl;
        cin >> N >> Q;
        for (int i = 1; i <= N; i++) cin >> A[i];
        IT.Build(1, 1, N);
        while (Q--){
            int c, u, v;
            cin >> c >> u >> v;
            if(c==0){
              int x;
              cin >> x;
              IT.Update0(1,1,N,u,v,x);
            }else if(c==1){
              int x;
              cin >> x;
              IT.Update1(1,1,N,u,v,x);
            }else if(c==2){
              cout << IT.getSum(1, 1, N, u, v) << endl;
            }
        }
    }
    return 0;
 }

