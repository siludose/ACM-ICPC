#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 220
const int inf=0x3f3f3f3f;
int n;
typedef struct Point
{
    int x;
    int y;
}point;
 point p[maxn];
 double distance(int i,int j)
{
    return sqrt((double)((p[i].x- p[j].x)*(p[i].x - p[j].x)+(p[i].y - p[j].y)*(p[i].y - p[j].y)));
}
double G[maxn][maxn];
int dp[maxn];
double dijkstra() {
    bool vis[maxn];

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) {
        dp[i] = G[0][i];
    }

    dp[0] = 0;
    vis[0] = true;

    for (int i = 0; i < n - 1; i++) {
        double m = inf; int x;
        for (int y = 0; y < n; y++) if (!vis[y] && m >= dp[y]) m = dp[x = y];
        vis[x] = true;
        for (int y = 0; y < n; y++) {
            if (!vis[y]) {
                double maxx = max(dp[x], G[x][y]);
                if (dp[y] > maxx) dp[y] = maxx;
            }
        }
    }

    return dp[1];
}
int main()
{
    //freopen("input1.txt","r",stdin);
    int count=0;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                G[i][j] = G[j][i] = distance(i, j);
            }
            G[i][i] = 0;
        }
        printf("Scenario #%d\n",++count);
        printf("Frog Distance = %.3f\n\n", dijkstra());
    }
    return 0;
}
