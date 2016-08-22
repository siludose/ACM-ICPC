#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 600
int n,m;
int zuo[maxn][maxn],shang[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m),n+m)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&zuo[i][j]);
                zuo[i][j]+=zuo[i][j-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&shang[i][j]);
                shang[i][j]+=shang[i-1][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i][j-1]+shang[i][j],dp[i-1][j]+zuo[i][j]);
            }
        }
        printf("%d\n",dp[n][m]);
        
    }
    return 0;
}
