#include<iostream>
#include<vector>
#include<cstdio>
#include<string.h>
#pragma warning(disable:4996)
#define inf 0x7fffffff
#define min(x,y)  x<y?x:y
using namespace std;
int n,m,goal;
vector<int>to[1010];
int cost[1010][1010];
int lowcost[1010][12];
bool vis[1010];
void dijstar(int beg)
{
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            lowcost[i][j]=inf;
        }
    }
    lowcost[beg][0]=0;
    for(int j=1;j<=n;j++)
    {
        int k=-1;
        int Min=inf;
        int markj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=10;j++)
            {
                if(!vis[i]&&lowcost[i][j]<Min)
                {
                    Min=lowcost[i][j];
                    markj=j;
                    k=i;
                }
            }
             
        }
        if(k==-1)break;
        vis[k]=true;
        for(int i=0;i<to[k].size();i++)
        {
            int nex=to[k][i];
            if(!vis[nex]&&lowcost[k][markj]+cost[k][nex]<lowcost[nex][markj+1])
            {
                lowcost[nex][markj+1]=lowcost[k][markj]+cost[k][nex];
            }
        }
    }
}
void init(int n)
{
	int i;
    for(i=0;i<=n;i++)
    {
        to[i].clear();
    }
    for(i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cost[i][j]=inf;
        }
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&goal))
    {
		init(n);
        if(n==0&&m==0&&goal==0)
        {
            break;
        }
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            to[a].push_back(b);
            to[b].push_back(a);
            cost[a][b]=c;
            cost[b][a]=c;
        }
        dijstar(0);
        int M=inf;
        for(int i=0;i<=10;i++)
        {
            if(lowcost[goal][i]!=inf)
            {
                M=min(M,lowcost[goal][i]);
            }
        }
        if(M==inf)
        {
            printf("no\n");
        }
        else
        {
            printf("%d",M);
        }
    } 
    return 0;
}