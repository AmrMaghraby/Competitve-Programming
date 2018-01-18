 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 int n;
 long  long ans=0;
 while(scanf("%d",&n)){
    if(n==0) break;
    int mxX=-1e9,mxY=-1e9,mxZ=-1e9,mnX=1e9,mnY=1e9,mnZ=1e9;
    while(n--){
        int x,y,z,d;
        scanf("%d %d %d %d",&x,&y,&z,&d);
        mxX=max(mxX,x);
        mxY=max(mxY,y);
        mxZ=max(mxZ,z);
        mnX=min(mnX,x+d);
        mnZ=min(mnZ,z+d);
        mnY=min(mnY,y+d);
    }
    ans = (-mxX+mnX)*(-mxY+mnY)*(-mxZ+mnZ);
    printf("%lld\n",ans>0?ans:0);
 }
}

