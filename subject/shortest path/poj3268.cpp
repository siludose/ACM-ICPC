#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1010;
const int INF=0x3f3f3f3f;
vector<int>g1[MAXN];
vector<int>g2[MAXN];
int cost1[MAXN][MAXN];
int cost2[MAXN][MAXN];
int n,m,x;
bool vis[MAXN];
int dist1[MAXN],dist2[MAXN];
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
void init(int N)
{
    for(int i=1;i<=N;i++)
    {
        g1[i].clear();
        g2[i].clear();
    }
}
void addedge(int u,int v,int w)
{
    g1[u].push_back(v);
    g2[v].push_back(u);
    cost1[u][v]=w;
    cost2[v][u]=w;
}
void Dijstar(int beg)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dist1[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty())que.pop();
    dist1[beg]=0;
    que.push(qnode(beg,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<g1[u].size();i++)
        {
            int v=g1[u][i];
            int cos=cost1[u][v];
            if(!vis[v]&&dist1[v]>dist1[u]+cos)
            {
                dist1[v]=dist1[u]+cos;
                que.push(qnode(v,dist1[v]));
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)dist2[i]=INF;
    while(!que.empty())que.pop();
    dist2[beg]=0;
    que.push(qnode(beg,0));
    while(!que.empty())
    {
        tmp=que.top();que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<g2[u].size();i++)
        {
            int v=g2[u][i];
            int cos=cost2[u][v];
            if(!vis[v]&&dist2[v]>dist2[u]+cos)
            {
                dist2[v]=dist2[u]+cos;
                que.push(qnode(v,dist2[v]));
            }
        }
    }
    int ans=0;
	for (int i = 1; i <= n; i++)
		if(i!=beg)
			ans = max(ans, dist1[i] + dist2[i]);
        
    printf("%d\n",ans);
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&x)!=EOF)
    {
        int u,v,w;
        init(n);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        Dijstar(x);
    }
    return 0;
}
