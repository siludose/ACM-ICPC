#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define N 2e5+5
int pos[10].n,m,match[10],ret;
bool vis[10],used[10],g[10][10],mp[10][10];
void solve()
{
	memset(match,-1,sizeof(match));
	memset(g,false,sizeof(g));
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[pos[i][j]]||mp[pos[i-1]][j])
				continue;
			g[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(mp[pos[1][i]]||mp[pos[n]][i])
			continue;
		g[1][i]=true;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(mp[pos[1]][i]||mp[pos[n]][i])
			continue;
		
	}
}
void get(int x)
{
	if(ret==0)return;
	if(x==n+1){solve();return;}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		pos[x]=i;
		vis[i]=true;
		get(x+1);
		vis[i]=false;
	}
}
int main()
{
	vis[1]=true;pos[1]=1;
	while(~scanf("%d%d",&n,&m)){
		if(n==0){
			printf("0\n");
			continue;
		}
		memset(mp,0,sizeof(mp));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			mp[v][u]=true;
		}
		ret=inf;
		get(2);
		printf("%d",ret);
	}
	return 0;
}
