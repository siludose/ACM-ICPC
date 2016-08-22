#include<iostream>
#include<string.h>
using namespace std;
#define maxn 110
int c[maxn];
int topo[maxn],t;
int G[maxn][maxn];
int m,n; 
bool dfs(int u)
{
	c[u]=-1;
	for(int v=1;v<=n;v++)
	{
		if(G[u][v])
		{
			if(c[v]<0)
				return false;
			else if(!c[v]&&!dfs(v))
				return false;
		}
	}
	c[u]=1;topo[t--]=u;
	return true;
}
bool toposort()
{
	t=n;
	memset(c,0,sizeof(c));
	for(int u=1;u<=n;u++)
	{
		if(!c[u])
			if(!dfs(u)) 
				return false;
	}
	return true;
}
int main()
{
	int u,v;
	t=0;
	while(scanf("%d %d",&n,&m))
	{
		if(m+n==0)
		{
			break;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			G[u][v]=1;
		}
		if(toposort())
		{
			for(int i=1;i<n;i++)
			{
				printf("%d ",topo[i]);
			}
			printf("%d",topo[n]);
		}
		memset(G,0,sizeof(G));
	}
	return 0;	
} 
