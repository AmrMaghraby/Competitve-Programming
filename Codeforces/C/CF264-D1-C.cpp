#include<bits/stdc++.h>
#define N 120000
using namespace std;
int i,j,k,l,n,m,v[N],c[N],c1,c2;
long long s1,s2,a,b,f[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&v[i]);
	for(i=1;i<=n;++i)scanf("%d",&c[i]);
	for(i=1;i<=m;++i){
		scanf("%I64d%I64d",&a,&b);
		for(j=1;j<=n;++j) f[j]=-1ll<<55;
		s1=s2=0; c1=c2=-1;
		for(j=1;j<=n;++j){
			long long tmp=-1ll<<55;
			if(c[j]!=c1)tmp=max(tmp,s1+b*v[j]);
			if(c[j]!=c2)tmp=max(tmp,s2+b*v[j]);
			tmp=max(tmp,f[c[j]]+a*v[j]);

			f[c[j]]=max(f[c[j]],tmp);
//			cout<<j<<" "<<c1<<" "<<c2<<" "<<tmp<<" "<<s1+b*v[j]<<" "<<s2+b*v[j]<<" "<<f[c[j]]<<endl;
			if(tmp>=s1){
				if(c1!=c[j])s2=s1,c2=c1;
				s1=tmp,c1=c[j];
			}
			else if(c[j]!=c1 && tmp>=s2)s2=tmp,c2=c[j];
		}
		printf("%I64d\n",s1);
	}
}
//6 3
//1 -2 3 4 0 -1
//1 2 1 2 1 1
//5 1
//s1 = 1
//s2 = 0
//c1 = 1
//c2 = ?
