#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N=100+3;
int cost[MAX_N][MAX_N];
int dis[MAX_N];
bool used[MAX_N];
const int INF=1<<29;
int n;
int prim()
{
	for(int i=0;i<n;i++)
	{
		dis[i]=INF;
		used[i]=false;
	}
	dis[0]=0;
	int res=0;
	while (true)
	{
		int v=-1;
		for (int u=0;u<n;u++)		
			if (!used[u]&&(v==-1||dis[u]<dis[v]))
				v=u;

		
		if (v==-1)
			break;
		used[v]=true;
		res+=dis[v];
		for(int u=0;u<n;u++)
			dis[u]=min(dis[u],cost[v][u]);
	}
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	memset(used,false,sizeof(used));
	cin>>n;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cost[i][j]=INF;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>cost[i][j];
		}
	}
	cout<<prim()<<endl;
	return 0;
}