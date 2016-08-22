#include<cstdio>
#include<cstring>
#include<cmath>
#include<string.h>
#define min(a,b) a<b?a:b
#define inf 0x3f3f3f3f
#define N 20

int dp[N][10][10][10][10],s[10][10][10][10],c[10][10];
int add(int x1,int y1,int x2,int y2)
{
    int ans=0,x,y;
    for(x=x1;x<=x2;x++)
        for(y=y1;y<=y2;y++)
            ans+=c[x][y];
    return ans;
}
int dfs(int k,int x1,int y1,int x2,int y2)
{
    if(dp[k][x1][y1][x2][y2]!=-1)
        return dp[k][x1][y1][x2][y2];
    int x,y,t1,t2,t;
    dp[k][x1][y1][x2][y2]=inf;
    if(x2>x1)
    {
        for(x=x1;x<x2;x++)
        {
            t1=dfs(k-1,x+1,y1,x2,y2);
            t2=dfs(k-1,x1,y1,x,y2);
            t=min(t1+s[x1][y1][x][y2],t2+s[x+1][y1][x2][y2]);
            dp[k][x1][y1][x2][y2]=min(dp[k][x1][y1][x2][y2],t);
        }
    }
    if(y2>y1)
    {
        for(y=y1;y<y2;y++)
        {
            t1=dfs(k-1,x1,y+1,x2,y2);
            t2=dfs(k-1,x1,y1,x2,y);
            t=min(t1+s[x1][y1][x2][y],t2+s[x1][y+1][x2][y2]);
            dp[k][x1][y1][x2][y2]=min(dp[k][x1][y1][x2][y2],t);
        }
    }
    return dp[k][x1][y1][x2][y2];
}
int main()
{
    //freopen("input.txt","r",stdin);
    int x1,x2,y1,y2,x,y,n;
    scanf("%d",&n);
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            scanf("%d",&c[i][j]);

    memset(dp,-1,sizeof(dp));
    for(x1=1;x1<=8;x1++)
        for(x2=x1;x2<=8;x2++)
            for(y1=1;y1<=8;y1++)
                for(y2=y1;y2<=8;y2++)
                {
                    int tmp=add(x1,y1,x2,y2);
                    dp[1][x1][y1][x2][y2]=s[x1][y1][x2][y2]=tmp*tmp;
                }
    dfs(n,1,1,8,8);
    double X,ans;
    X=1.0*add(1,1,8,8);
    X=(X/n)*(X/n);
    ans=sqrt(1.0*dp[n][1][1][8][8]/n-X);
    printf("%.3f\n",ans);
    return 0;
}
