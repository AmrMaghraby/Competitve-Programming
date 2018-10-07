/*
Intention: Given a character relationship tree, and the starting point, starting from the starting point, each person can only notify one person per minute, and ask how many minutes to notify everyone.

DFS: For each point, first dfs all neighbors (except for the one that calls themselves) and get a few answers,
Then sort, add 1, 2, 3, ... in turn to add a small number. Returns the maximum value in the number after the addition.

*/
 #include<bits/stdc++.h>
 #define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
 #define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
 using namespace std;
 struct ArcNode{
	int to;
	ArcNode*next;
 };
 struct Node{
	int Dis;
	int n;
	bool vis;
	ArcNode*List;
 }node[100001];
 void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	node[from].n++;
 }
 void DArc(int from,int to){
	Arc(from,to);Arc(to,from);
 }
 int dfs(int rt){
	if(node[rt].n==0) return 0;
	int *ans=new int[node[rt].n];
	ArcNode*temp=node[rt].List;
	int n=0;node[rt].vis=1;
	while(temp){
		if(!node[temp->to].vis){
			ans[n++]=dfs(temp->to);
		}
		temp=temp->next;
	}
	sort(ans,ans+n);
	int ANS=0;
	for(int i=0;i<n;i++){
		ans[i]+=n-i;
		if(ans[i]>ANS) ANS=ans[i];
	}
	return ANS;
 }
 int N;
 int main(){
	while(cin>>N){
		FOR(i,N) node[i].n=-1,node[i].vis=0,node[i].List=NULL;
		FOR(i,N){
			int a;
			while(~scanf("%d",&a)&&a){
				DArc(i,a);
			}
		}
		int rt;
		scanf("%d",&rt);
		 node[rt].n++;
		int ANS=dfs(rt);
		printf("%d\n",ANS);
	}
 return 0;
 }

