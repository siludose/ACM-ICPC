#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#pragma  warning(disable:4996)
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=2010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator<(const qnode &r)const
    {
        return c<r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijstar(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=0;
    dist[start]=INF;
    priority_queue<qnode> que;
    while(!que.empty())que.pop();
    que.push(qnode(start,INF));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]<min(cost,dist[u]))
            {
                dist[v]=min(cost,dist[u]);
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
        E[u].push_back( Edge(v,w) );
}
int t,n,m;
int u,v,w;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i++)
			E[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
		Dijstar(n, 1);
        printf("Scenario #%d:\n",cas);
        printf("%d\n\n",dist[n]);
    }
    return 0;
}
