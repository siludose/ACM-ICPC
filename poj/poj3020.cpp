#include<iostream>
#include<string.h>
#include<algorithm>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 45
int t,n,m,num;
char temp;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int index[maxn][maxn];
bool G[maxn*maxn][maxn*maxn];
bool used[maxn*maxn];
int linker[maxn*maxn];
void init()
{
    memset(index,0,sizeof(index));
    memset(G,false,sizeof(G));
    num=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
			cin >> temp;
            if(temp=='*')
            {
                index[i][j]=++num;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(index[i][j]>0)
            {
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>0&&y>0&&x<=n&&y<=m)
                    {
                        if(index[x][y]>0)
                        {
                            G[index[i][j]][index[x][y]]=G[index[x][y]][index[i][j]]=true;
                        }
                    }
                }
            }

        }
    }
}
bool dfs(int u)
{
    for(int v=1;v<=num;v++)
    {
        if(G[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==0||dfs(linker[v]))
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
    memset(linker,0,sizeof(linker));
    for(int u=1;u<=num;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
     return res;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        init();
        printf("%d\n",num-hungry()/2);
    }
    return 0;
}
