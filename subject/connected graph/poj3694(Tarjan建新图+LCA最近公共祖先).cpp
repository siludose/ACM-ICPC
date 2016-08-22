/*
这是一个无向图
首先还是要求出图的强连通分块，图的割点数量
然后题意说会输入一些边，问每一次加边桥的数量剩下多少割点

我们可以知道从这条边的两个点作为起点，到其最近公共祖先的所有点都是需要删除的割点
当然，有些点是会被重复删除的，我们需要对其做标记
这时候要用LCA算法求最近公共祖先
LCA的算法原理是什么
首先建好的新图由于不存在环，是可以当成树的
我们先随便选一个点当作根对其进行dfs或者bfs求树的每个节点的深度
然后根据这个深度去找两个点的最近祖先
 */
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#pragma warning(disable:4996)
using namespace std;
const int maxn=150;
const int maxm=20010;
struct Edge
{
    int to;
    int next;
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],stack[maxn],belong[maxn];
int index,top,scc;
bool instack[maxn];
int n,m;
bool map[maxn][maxn];
bool use[maxn];
std::map<int, int>mp;
void adde(int u, int v);
struct EE
{
	int v, next;
}ee[maxn << 1];//这是为新图建的结构体
int cntt, headd[maxn];
int root, p[maxn], d[maxn];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++index;
    stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            if(low[u]>low[v])low[u]=low[v];
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=stack[--top];
            instack[v]=false;
            belong[v]=scc;
        }while(v!=u);
    }
}


void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
	memset(headd, -1, sizeof(headd));
}

bool ishash(int u,int v)
{
    if(mp[u*maxn+v])
        return true;
    if(mp[u+v*maxn])
        return true;
    mp[u*maxn+v]=mp[v*maxn+u]=1;
    return false;
}
void make_new_map()
{
    for(int i=1;i<=n;i++)
        for (int j = head[i]; j != -1; j = edge[j].next)
        {
            if (belong[i] != belong[edge[j].to]) {
                if(!ishash(belong[i],belong[edge[j].to])){
					adde(belong[i], belong[edge[j].to]);
					adde(belong[edge[j].to], belong[i]);
                }
            }
        }        
}
void solve1(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    index=top=scc=0;
    tarjan(1,1);
    make_new_map();
}



/*********************************LCA*************************************/

void adde(int u,int v)
{
    ee[cntt].v=v;
    ee[cntt].next=headd[u];
    headd[u]=cntt++;
}
void dfs(int v,int P,int D)
{
    p[v]=P;
    d[v]=D;
	for (int i = headd[v]; i != -1; i = ee[i].next)
		if (ee[i].v != P)
			dfs(ee[i].v,v, D + 1);
}
void initt()
{
	root = 1;
    dfs(root,-1,0);
}
void lca(int u,int v)
{
    if(!use[u])
	{
		scc--; use[u] = true;
	}
    if(!use[v])
	{
		scc--; use[v] = true;
	}
    while(d[u]>d[v])
    {
        u=p[u];
		if (!use[u])
		{
			scc--; use[u] = true;
		}      
    }
    while(d[v]>d[u])
    {
        v=p[v];
        if(!use[v])
		{
			scc--; use[v] = true;
		}
    }
    while(u!=v)
    {
        u=p[u];
        v=p[v];
        if(!use[u])
		{
			scc--; use[u] = true;
		}
        if(!use[v])
		{
			scc--; use[v] = true;
		}
    }
    printf("%d\n",scc);
}
void solve2(int cas)
{
	int q, u, v;
    scanf("%d",&q);
	printf("Case %d:\n",cas);
    while(q--)
    {
        scanf("%d%d",&u,&v);
        lca(u,v);
    }
	mp.clear();
}

int main()
{
	freopen("input.txt", "r", stdin);
	int cas = 0;
    while(scanf("%d%d",&n,&m),(n+m))
    {
		int u, v;
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        solve1(n);
        initt();
		solve2(++cas);
    }
    return 0;
}