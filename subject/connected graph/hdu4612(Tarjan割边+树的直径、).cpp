/*
这道题目首先就给我们说了割边，
然后说想要消除割边
问如果只添加一条边最多能够消除多少个割边
首先还是要用模板跑一边遍，建新图
用两遍dfs或者两遍bfs算出树的直径
 */
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:102400000,102400000")//手动加栈
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int MAXN=200010;
const int MAXM=2000010;

struct Edge
{
    int to,next;
	bool cong;
    bool cut;
}edge[MAXM];
struct Node
{
	int u, v;
}node[MAXM];
int head[MAXN];
int low[MAXN],dfn[MAXN];
bool Instack[MAXN];
int Stack[MAXN];
int Belong[MAXN];
int block,tot,Index,top,bridge;

vector<int> vec[MAXN];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,bool buer)
{
    edge[tot].to=v;
    edge[tot].cut=false;
    edge[tot].next=head[u];
	edge[tot].cong = buer;
    head[u]=tot++;
}
void Tarjan(int u,int pre,bool buer)
{
    int v;
    dfn[u]=low[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre&&(!buer))continue;
        if(!dfn[v])
        {
            Tarjan(v,u,edge[i].cong);
            if(low[v]<low[u])low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
        }
        else if(Instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        block++;
        do{
            v=Stack[--top];
            Instack[v]=false;
            Belong[v]=block;
        }while(v!=u);
    }
}
int dep[MAXN];
int mark;
void dfs(int beg)
{
	for (int i = 0; i < vec[beg].size(); i++)
	{
		int v = vec[beg][i];
		if (dep[v] != -1)continue;
		dep[v] = dep[beg] + 1;
		dfs(v);
	}
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(Instack,0,sizeof(Instack));
    bridge=Index=top=block=0;
    Tarjan(1,0,false);
    for(int i=1;i<=block;i++)
        vec[i].clear();
    for(int i=1;i<=N;i++){
        for(int j=head[i];j!=-1;j=edge[j].next){
            if(edge[j].cut)
            {
                vec[Belong[i]].push_back(Belong[edge[j].to]);
            }
        }
    }
    memset(dep,-1,sizeof(dep));
	dep[1] = 0;
	dfs(1);
	int k = 1;
	for (int i = 1; i <= block; i++)
		if (dep[i] > dep[k])
			k = i;
    memset(dep,-1,sizeof(dep));
	dep[k] = 0;
	dfs(k);
	int ans = 0;
	for (int i = 1; i <= block; i++)
		ans = max(ans, dep[i]);
    printf("%d\n",block-ans-1);//要减一是因为连通块比桥多1，这里也可以用bridge来减的
}
bool cmp(struct Node a, struct Node b)
{
	if (a.u == b.u)
		return a.v < b.v;
	return a.u < b.u;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m),(n+m))
    {
        init();
        int u,v;
		for (int i = 0; i < m;i++)
        {
            scanf("%d%d",&u,&v);
			if (u == v)continue;
			if (u > v)swap(u, v);
			node[i].v = v;
			node[i].u = u;
        }
		sort(node, node + m, cmp);//对边进行判重也是这道题的大头之一
		for (int i = 0; i < m; i++)
		{
			if (i == 0 || node[i].u != node[i - 1].u || node[i].v != node[i - 1].v)
			{
				if (i < m - 1&&(node[i].u == node[i + 1].u&&node[i].v == node[i + 1].v))
				{
					addedge(node[i].u, node[i].v, true);
					addedge(node[i].v, node[i].u, true);
				}
				else
				{
					addedge(node[i].u, node[i].v, false);
					addedge(node[i].v, node[i].u, false);
				}
			}	
		}
        solve(n);
    }
    return 0;
}
