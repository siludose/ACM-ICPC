#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
//#pragma warning(disable:4996)
#define ll long long
using namespace std;
int t,n,m;
const int MAXN=100100;//最大点数
const int MAXM=1000100;//最大边数
int F[MAXN];//并查集使用
struct Edge
{
    int u,v,w;
}edge[MAXM];//存储边的信息，包括起点/终点/权值
ll res;
vector<int> to[MAXN];
vector<int> val[MAXN];
int tol;//边数，加边前赋值为0
bool vis[MAXN];
void addedge(int u,int v,int w)
{
    edge[tol].u=u;
    edge[tol].v=v;
    edge[tol++].w=w;
}
bool cmp(Edge a,Edge b)
{//排序函数，讲边按照权值从小到大排序
    return a.w<b.w;
}
int find(int x)
{
    if(F[x]==-1)return x;
    else return F[x]=find(F[x]);
}
ll Kruskal(int n)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    ll cnt=0;//计算加入的边数
    ll ans=0;
    for(int i=0;i<tol;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            to[u].push_back(v);
            to[v].push_back(u);
            val[u].push_back(w);
            val[v].push_back(w);
            ans+=w;
            F[t1]=t2;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    if(cnt<n-1)return -1;//不连通
    else return ans;
}
ll dfs(int temp)
{
	ll cb = 0, nb = 0;
	if (!vis[temp])
	{
		vis[temp] = true;
		for (int i = 0; i < to[temp].size(); i++)
		{
			int nex = to[temp][i];
			if (!vis[nex])
			{
				nb = dfs(nex);
				cb += nb;
				res += nb*(n - nb)*val[temp][i];
			}		
		}
	}
	return 1 + cb;
}
void solve()
{
	res = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (to[i].size() == 1)
			break;
	}
	dfs(i);
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    int u,v,w;
    while(t--)
    {
		tol = 0; memset(vis, false, sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        printf("%I64d ",Kruskal(n));
		solve();
		double y = 1.0*n*(n - 1) / 2;
        printf("%.2lf\n",(double)res/y);
		for (int i = 1; i <= n; i++)
		{
			to[i].clear();
			val[i].clear();
		}
    }
    return 0;
}
