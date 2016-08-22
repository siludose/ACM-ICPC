#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#define maxn 3003
#define inf 0x7fffffff
using namespace std;
int n,m;
int lowcost[maxn][maxn];
bool vis[maxn];
vector<int> to[maxn];
void dijstar(int beg)
{
    for(int i=1;i<=n;i++)
    {
        lowcost[beg][i]=inf;vis[i]=false;
    }
    lowcost[beg][beg]=0;
    for(int j=1;j<=n;j++)
    {
        int k=-1;
        int Min=inf;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&lowcost[beg][i]<Min)
            {
                Min=lowcost[beg][i];
                k=1;
            }
        }
        if(k==-1)break;
        vis[k]=true;
        for(int i=0;i<=to[k].size();i++)
        {
            int nex=to[k][i];
            if(!vis[nex]&&lowcost[beg][k]+cost[k][nex]<lowcost[beg][nex])
            {
                lowcost[beg][nex]=lowcost[beg][k]+cost[k][nex];
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(cost,0x3f,sizeof(cost));
    for(int i=0;i<m;i++)
    {
        to[n].push_back(m);
    }
    for(int i=1;i<=n;i++)
    {
        dijstar(i);
    }
    for(int )
    return 0;
}