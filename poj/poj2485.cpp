#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 510
#define inf 0x3f3f3f3f
int t,n;
int dist[maxn][maxn];
int lowc[maxn];
bool vis[maxn];
int prim()
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++)lowc[i]=dist[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=inf;
        int p=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==inf)return -1;
        ans=max(minc,ans);
        vis[p]=true;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&lowc[j]>dist[p][j])
            {
                lowc[j]=dist[p][j];
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&dist[i][j]);
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
