#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=20010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator<(const qnode &r)const
    {
        return c>r.c;
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
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
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
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
//	bool flag=true;
//	for(int i=0;i<E[u].size();i++)
//	{
//		if(E[u][i].v==v)
//		{
//			E[u][i].cost=min(E[u][i].cost,w);flag=false;
//		}
//	}
//	if(flag)
    	E[u].push_back( Edge(v,w) );
}
int t,n;
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&t,&n)!=EOF)
    {
        int u,v,w;
        for(int i=1;i<=n;i++)
            E[i].clear();
        for(int i=1;i<=t;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        Dijstar(n,1);
        printf("%d\n",dist[n]);
    }
    return 0;
}
