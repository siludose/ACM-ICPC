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
void floyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (G[i][j]>max(G[i][k] , G[k][j]))
                {
                    G[i][j] = max(G[i][k], G[k][j]);
                }
            }
        }
    }
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
        floyd();
        printf("Scenario #%d\n",count);
        printf("Frog Distance = %.3f\n\n",G[0][1]);
    }
    return 0;
}
