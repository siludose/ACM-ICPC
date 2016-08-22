#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=510;
int n,m,u,v;
bool g[maxn][maxn];
bool used[maxn];
int linker[maxn];
bool dfs(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(g[u][v]&&!used[v])
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
int hungry()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=1;u<=n;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u][v]=true;
        }
        printf("%d\n",hungry());
    }
    return 0;
}
