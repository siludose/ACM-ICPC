#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=110;
const int INF=0x3f3f3f3f;
int t,n,m,ans;
int u,v,w;
int cost[MAXN][MAXN];
bool vis[MAXN];
int pre[MAXN];
int lowc[MAXN];
int Max[MAXN][MAXN];
bool used[MAXN][MAXN];
int Prim(int cost[][MAXN],int n)
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,0,sizeof(used));
    vis[0]=true;
    pre[0]=-1;
    for(int i=1;i<n;i++)
    {
        lowc[i]=cost[0][i];
        pre[i]=0;
    }
    lowc[0]=0;
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j])
        {
                minc=lowc[j];
                p=j;
        }
        if(minc==INF)
			return -1;
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0;j<n;j++)
        {
            if(vis[j])Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }
    return ans;
}
int smst(int cost[][MAXN],int n)
{
    int Min=INF;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(cost[i][j]!=INF&&!used[i][j])
            {
                Min=min(Min,ans+cost[i][j]-Max[i][j]);
            }
        }
    if(Min==INF)return -1;
    return Min;
}
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
                cost[i][j]=INF;
            else
                cost[i][j]=0;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);init(n);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);u--;v--;
            cost[u][v]=w;
            cost[v][u]=w;
        }
        ans=Prim(cost,n);
        if(ans==-1)
        {
            printf("Not Unique!\n\n");continue;
        }
        int num=smst(cost,n);
        if(num==ans)
        {
            printf("Not Unique!\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
