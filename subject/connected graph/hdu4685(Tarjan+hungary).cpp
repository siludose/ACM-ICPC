#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int t,n,m;
#define MAXN 1010

int linker[MAXN];
bool used[MAXN];
int uN,vN;
int g[MAXN][MAXN];
bool dfs(int u)
{
    for(int v=1;v<=vN;v++)
    {
        
        if(g[u][v]&& !used[v] )
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=1;u<=uN;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}




int lx[MAXN];
const int MAXM=500100;
int tot,head[MAXN];
int Belong[MAXN],Stack[MAXN],dfn[MAXN],low[MAXN],num[MAXN];
bool Instack[MAXN];
int top,Index,scc;
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
    dfn[u]=low[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
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
    memset(Instack,0,sizeof(Instack));
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    top=Index=scc=0;
    for(int i=1;i<=N;i++)
        if(!dfn[i]) Tarjan(i);
}

int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        cas++;
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            int out,v;
            scanf("%d",&out);
            for(int j=1;j<=out;j++)
            {
                scanf("%d",&v);
                g[i][v]=true;
            }
        }
        uN=n;
        vN=m;
        int res=hungary();
        vN=uN=n+m-res;
        for(int i=1;i<=uN;i++)
            for(int j=m+1;j<=vN;j++)
                g[i][j]=true;
        for(int i=n+1;i<=uN;i++)
            for(int j=1;j<=vN;j++)
                g[i][j]=true;

        hungary();

        memset(lx,-1,sizeof(lx));
        for(int i=1;i<=uN;i++)
            if(linker[i]!=-1)
                lx[linker[i]]=i;

        init();
        for(int i=1;i<=vN;i++)
            for(int j=1;j<=vN;j++)
                if(g[i][j]&&j!=lx[i])
                    addedge(lx[i],j);
        solve(vN);
        printf("Case #%d:\n",cas);
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            ans.clear();
            for(int j=1;j<=m;j++)
                if(g[i][j]&&Belong[j]==Belong[lx[i]])
                    ans.push_back(j);
            int sz=ans.size();
            printf("%d",sz);
            for(int i=0;i<sz;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
