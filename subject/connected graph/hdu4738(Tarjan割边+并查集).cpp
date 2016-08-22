/*
这道题目还多使用了并查集，用来判断图中的每一个点是否连通
这道题目的Tarjan算法还有一个功能那就是边

 */
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int MAXN=1010;
const int MAXM=2000010;
struct Edge
{
    int to,next;
    bool cut;
    int cost;
}edge[MAXM];
int tot,head[MAXN];
int top,Index,bridge;
int dfn[MAXN],low[MAXN],num[MAXN],Stack[MAXN];
bool Instack[MAXN];int add_block[MAXN];bool cut[MAXN];
int F[MAXN];

void addedge(int u,int v,int cost)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cost=cost;
    edge[tot].cut=false;
    head[u]=tot++;
}
void init()
{
	memset(F,-1,sizeof(F));
    tot=0;
    memset(head,-1,sizeof(head));
}
void Tarjan(int u,int pre)
{
    int v;
    dfn[u]=low[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    int son=0;
    int pre_num=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre&&pre_num==0)//这里如果是1或者以上的话，那么就不用continue；
		{                     //如此处理重边
			pre_num++;
			continue;
		}
        if(!dfn[v])
        {
        	son++;
            Tarjan(v,u);
            if(low[u]>low[v])low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
            if(u!=pre&&low[u]>=dfn[u])
            {
            	cut[u]=true;
            	add_block[u]++;
			}
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(u == pre && son > 1)cut[u] = true;
    if(u == pre)add_block[u] = son - 1;
	Instack[u] = false;
    top--;
}
int find(int x)
{
	if(F[x]==-1)return x;
	else return F[x]=find(F[x]);
}
void bing(int u,int v)
{
	int t1=find(u);
	int t2=find(v);
	if(t1!=t2)
		F[t1]=t2;
}
void solve(int N,int M)
{
    memset(dfn,0,sizeof(dfn));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    memset(Instack,0,sizeof(Instack));
    top=Index=bridge=0;
    for(int i=1;i<=N;i++)
        if(!dfn[i])Tarjan(i,i);
    int ans=0x3f3f3f3f;
    for(int u=1;u<=N;u++)
    	for(int i=head[u];i!=0;i=edge[i].next)
    		if(edge[i].cut)
    			ans=min(ans,edge[i].cost);
    if(ans==0x3f3f3f3f)
    	printf("%d\n",-1);
    else if(ans==0)
    	printf("%d\n",1);
	else
    	printf("%d\n",ans);
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m),(n+m))
    {
        init();
        int u,v,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
			addedge(u,v,c);
        	addedge(v,u,c);
        	bing(u,v);
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        	if(find(i)!=find(1))
        		flag=false;
        if(!flag)
        {
        	printf("0\n");continue;
		}		
        solve(n,m);
     }
    return 0;
}
