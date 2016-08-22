#include<iostream>
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
#define maxn 100
using namespace std;
struct Edge
{
    int v;
    int next;
}e[maxn<<1];
int cnt;
int head[maxn];
void adde(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int root,p[maxn],d[maxn];
void dfs(int v,int P,int D)
{
    p[v]=P;
    d[v]=D;
    for(int i=head[v];i!=-1;i=e[i].next)
        if(e[i].v!=P)
            dfs(e[i].v,v,D+1);
}
void init()
{
    dfs(root,-1,0);
}
int lca(int u,int v)
{
    while(d[u]>d[v])
        u=p[u];
    while(d[v]>d[u])
        v=p[v];
    while(u!=v)
    {
        u=p[u];
        v=p[v];
    }
    return u;
}
int n;

int main()
{
    cnt=0;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&root);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    init();
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        cout<<lca(u,v)<<endl;
    }
    return 0;
}