/*
 IDEA : is cayley Thereom the problem is asking about numbre of unique trees which is N^(n-2) cayley therom
*/
#include <cstdio>

#define i64 long long

i64 Cal (i64 s,i64 index,i64 mod)
{
	i64 ans=1;
	s%=mod;
	while (index>=1)
	{
		if ((index&1)==1)   //奇数
			ans=(ans*s)%mod;
		index>>=1;
		s=s*s%mod;
	}
	return ans;
}

int main ()
{
	int T;
	scanf("%d",&T);
	for (int Cas=1;Cas<=T;Cas++)
	{
		i64 n;
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",Cas,Cal(n,n-2,2000000011));
	}
	return 0;
}
