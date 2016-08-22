#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 1010
const int inf=0x3f3f3f3f;
int n;
bool vis[maxn];
typedef struct Point
{
    int x;
    int y;
}point;
point p[maxn];
double distance(int sx,int sy,int ex,int ey)
{
    return sqrt((sx-ex)*(sx-ex)+(sy-ey)*(sy-ey));
}
double dfs(int rt,double cost)
{
    double mincost=inf;
    if(rt==1)
    {
        return cost;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            double dis=distance(p[rt].x,p[rt].y,p[i].x,p[i].y);
            if(cost<dis)
            {
				mincost = min(dfs(i, dis), mincost);
            }
			else
			{
				mincost = min(dfs(i, cost), mincost);
			}
            
            vis[i]=false;
        }
    }
    return mincost;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int count=0;
    while(scanf("%d",&n))
    {
    	if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
		vis[0] = true;
        printf("Scenario #%d\n",++count);
        printf("Frog Distance = %.3f\n",dfs(0,0));
    }

    return 0;
}
