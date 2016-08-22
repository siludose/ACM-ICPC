/*
这是一个无向图，奶牛们希望每次从一个点走到另一个点的时候有不少于一条路
所以我们面对的问题是要向这张图里面添加多少个点才能够使图变为双连通图
首先我们可以使用Tarjan算法建出新图然后看看有多少个点的度数是为1的
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=5050;
struct Edge
{
    int v,next;
    bool cut;
}edge[MAXN];
int head[MAXN];
int Stack[MAXN],dfn[MAXN],low[MAXN],Belong[MAXN];
bool Instack[MAXN];
int tot,scc,Index,top,bridge;

void addedge(int u,int v)
{
    edge[tot].v=v;
    edge[tot].next=head[u];
    edge[tot].cut=false;
    head[u]=tot++;
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void Tarjan(int u,int pre)
{
    int v;
    dfn[u]=low[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==pre)continue;
        if(!dfn[v])
        {    
            Tarjan(v,u);
            if(low[u]>low[v])low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
        }
        else if(Instack[v]&&low[u]>dfn[v])
        {
            low[u]=dfn[v];
        }
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do{
            v=Stack[--top];
            Instack[v]=false;
            Belong[v]=scc;
        }while(u!=v);
    }
}   
int du[MAXN];
void solve(int N)
{
    memset(Instack,0,sizeof(Instack));
    memset(dfn,0,sizeof(dfn));
    top=Index=scc=0;
    Tarjan(1,0);
    int ans=0;
    memset(du,0,sizeof(du));
    for(int i=0;i<=N;i++)
        for(int j=head[i];j!=-1;j=edge[j].next)
            if(edge[j].cut)
                	du[Belong[i]]++;//新图的每个顶点度数+1
    for(int i=1;i<=scc;i++)
        if(du[i]==1)
            ans++;
    printf("%d\n",(ans+1)/2);

}
int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        solve(n);
    }
    return 0;
}
