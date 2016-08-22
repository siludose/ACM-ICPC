/*
问最多可以添加多少条边使得这张有向图仍然不是强连通图
所以此题可以模拟只剩下一条边为桥的情况
对每个连通分块进行模拟，当且仅当这个连通分块入度为0或者出度为0
 */
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
const int MAXN=100100;
const int MAXM=100100;
int tot,head[MAXN],scc,Index,top;
int low[MAXN],dfn[MAXN],Stack[MAXN],Instack[MAXN],Belong[MAXN],num[MAXN];
int in[MAXN], out[MAXN];
struct Edge
{
    int to,next;
}edge[MAXM];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void Tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            if(low[v]<low[u])low[u]=low[v];
        }
        else if(Instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            Instack[v]=false;
            Belong[v]=scc;
            num[scc]++;
        }while(v!=u);
    }
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    top=Index=scc=0;
    for(int i=1;i<=N;i++)
        if(!dfn[i])
            Tarjan(i);
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        init();
        int n,m,u,v;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        solve(n);
        if(scc==1)
		{
			printf("Case %d: %d\n",cas,-1);
			continue;
		} 
		for (int i = 1; i <= scc; i++)
		{
			in[i] = 0; out[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = head[i]; j != -1; j=edge[j].next)
			{
				int v = edge[j].to;
				if (Belong[i] == Belong[v])continue;
				in[Belong[v]]++;
				out[Belong[i]]++;
			}
		}
        ll sss=(ll)n*(n-1)-m;
        ll ans=0;
        for(int i=1;i<=scc;i++)
        {
			if(in[i]==0||out[i]==0)
				ans=max(ans,sss-(ll)num[i]*(n-num[i]));
        }
        printf("Case %d: %lld\n",cas,ans);
    }


    return 0;
}
