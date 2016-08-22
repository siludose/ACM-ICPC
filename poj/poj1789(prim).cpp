#include<iostream>
#include<string.h>
using namespace std;
#define maxn 2010
#define inf 0x3f3f3f3f
int n;
char s[maxn][maxn];
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
        ans+=minc;
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
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    dist[i][i]=0;
                }
                else
                {
                    int count=0;
                    for(int k=0;k<7;k++)
                    {
                        if(s[i][k]!=s[j][k])
                        {
                            count++;
                        }
                    }
                    dist[i][j]=dist[j][i]=count;
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",prim());
    }
    return 0;
}
