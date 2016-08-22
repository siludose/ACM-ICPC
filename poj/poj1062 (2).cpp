#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define mem(a) memset(a,0,sizeof(a))
#define MAXN 105
#define INF 1000000007

int Price[MAXN],Edge[MAXN][MAXN],Level[MAXN];
int vis[MAXN], d[MAXN];
int N,M,ans;

void init()
{
    mem(Price); mem(Level);
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            Edge[i][j] = INF;//????????????
        }
    }
}

void read()
{
    int i,j,X,T,TP;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%d",&Price[i], &Level[i], &X);
        for(j=0;j<X;j++)
        {
            scanf("%d %d", &T, &TP);
            Edge[T][i] = TP;//???
        }
        Edge[0][i] = Price[i];
    }
}

int dijkstra()
{
    for(int i=1;i<=N;i++)d[i] = Price[i];//??0???????????????
    for(int i=1;i<=N;i++)
    {
        int temp = INF,x;
        for(int j=1;j<=N;j++)if(!vis[j] && d[j]<=temp)temp = d[x = j];
        vis[x] = 1;
        for(int j=1;j<=N;j++)if(d[x]+Edge[x][j] < d[j] && !vis[j])d[j] = d[x]+Edge[x][j];//??????????,??!vis[j]
    }
    return d[1];//?????????????????
}

int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%d %d", &M, &N))
    {
        init();
        read();
        ans = INF;
        for(int i=1;i<=N;i++)
        {
            int minLevel = Level[i];//?????????????
            for(int j=1;j<=N;j++)
            {
                if(Level[j] - minLevel > M || minLevel > Level[j])vis[j] = 1;//?????????,?????M,?????
                else vis[j] = 0;
            }
            int now = dijkstra();
            ans = MIN(ans,  now);
        }
        printf("%d\n", ans);
    }
    return 0;
}
