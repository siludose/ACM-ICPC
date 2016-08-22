/*
    这道题非常套路哦，
    就是要求割点的数量
    谢谢斌哥模板
 */#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 105
#define maxm 100100
struct Edge
{
    int to,next;
    bool cut;
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
bool cut[maxn];
int add_block[maxn];//删除一个点后增加的连通块
int bridge;
int n,u,v;
char ch;
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=0;//需要增加这个变量
    head[u]=tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    int son=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)continue;//有向图必备
        if(!dfn[v])
        {
            son++;
            Tarjan(v,u);
            if(low[v]<low[u])low[u]=low[v];
            //桥
            //一条无向边(u,v)是桥，当且仅当(u,v)为树枝边，且满足DFS(u)<Low(v)。
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
            //割点
            //一个顶点u是割点，
            //当且仅当满足1或2
            //1u为树根，且u有多于一个子树
            //2u不为树根，且满足存在（u,v）为树枝边（或称父子边）
            //即u为v在搜索树种的父亲
            if(u!=pre&&low[v]>=dfn[u])
            {
                cut[u]=true;
                add_block[u]++;
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
        //树根，分支树大于1
    }
    if(u==pre&&son>1)cut[u]=true;
    if(u==pre)add_block[u]=son-1;
    Instack[u]=false;
    top--;
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(cut,0,sizeof(cut));
    memset(add_block,0,sizeof(add_block));
    Index=top=0;
    for(int i=1;i<=N;i++)
        if(!dfn[i])
            Tarjan(i,i);
}
int main()
{
	//freopen("input.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
    	//printf("%d\n",123);
        init();
        while(scanf("%d",&u),u)//这道题的输入方式有一点奇怪，需要注意一下
        {
            while(scanf("%d%c",&v,&ch),v)
            {
                addedge(u,v);
                addedge(v,u);
                if(ch=='\n')
                    break;
            }
        }
        solve(n);
        int ans=0;
        for(int i=1;i<=n;i++)    
            if(cut[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
