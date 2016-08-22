#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
const int MAXN=1200;
const int INF=0x3f3f3f3f;
bool  vis[MAXN];
int pre[MAXN];
double lowc[MAXN];
double Max[MAXN][MAXN];
bool used[MAXN][MAXN];
double max(double a, double b)
{
	return a > b ? a : b;
}
double Prim(double cost[][MAXN],int n)
{
    double ans=0;
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
        double minc=INF*1.0;
        int p=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j])
        {
                minc=lowc[j];
                p=j;
        }
        if(minc==INF)return -1;
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0;j<n;j++)
        {
            if(vis[j]&&j!=p) Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }
    return ans;
}
struct PP
{
    double x,y;
    double cc;
}pp[MAXN];
double cost[MAXN][MAXN];
int t;
double distance(double x1,double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	//freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&t);
    while(t--)
    {
		memset(cost, 0, sizeof(cost));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&pp[i].x,&pp[i].y,&pp[i].cc);
        }
        for(int i=0;i<n;i++)
            for(int j=1+i;j<n;j++)
					cost[i][j]=cost[j][i]=distance(pp[i].x,pp[i].y,pp[j].x,pp[j].y);
        double ans=Prim(cost,n);
        double ra=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
				if (i == j)continue;
                if(used[i][j])
                {
                    ra=max(ra,(pp[i].cc+pp[j].cc)/(ans-cost[i][j]));
                }
                else
                {
                    ra=max(ra,(pp[i].cc+pp[j].cc)/(ans-Max[i][j]));
                }

            }
        printf("%.2lf\n",ra);
    }
    return 0;
}
