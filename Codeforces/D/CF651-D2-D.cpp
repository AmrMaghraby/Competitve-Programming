#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,t,res,l,r;
long long sum;
int c[1000005];
char x;
int main() {
	cin>>n>>a>>b>>t;
	for (int i=1;i<=n;++i)
    {
		cin>>x;
		if(x=='w')c[i]=b+1;
        else c[i]=1;
        c[i+n]=c[i];
		sum+=c[i];
	}
	sum-=c[1];
	l=2;
	r=n+1;
	while(l<=n+1 && r<=2*n)
    {
		sum+=c[r];
		++r;
		while(r-l>n || sum+(r-l-1+min(n-l+1,r-n-2))*a>t)sum-=c[l++];
		if(l>n+1)break;
		res=max(res,r-l);
	}
	cout<<res<<'\n';
	return 0;
}
