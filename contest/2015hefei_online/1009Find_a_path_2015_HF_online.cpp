/*简单DP
首先要进行公式的转换
dp[i][j][k]k代表各点的值的和

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
#define maxn 32
int t,n,m,ans;
int a[maxn][maxn];
int dp[maxn][maxn][maxn*2*maxn];
#define inf 0x3f3f3f3f
void solve()
{
	int temp = (n + m - 1);
	dp[1][1][a[1][1]]=a[1][1]*a[1][1]*temp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=((n+m-1)*30);k++)
            {
                if(dp[i][j][k]!=inf)
                {
                    if(i!=n)
                    {
                        dp[i+1][j][k+a[i+1][j]]=min(dp[i+1][j][k+a[i+1][j]],dp[i][j][k]+a[i+1][j]*a[i+1][j]*temp);
                    }
                    if(j!=m)
                    {
                        dp[i][j+1][k+a[i][j+1]]=min(dp[i][j+1][k+a[i][j+1]],dp[i][j][k]+a[i][j+1]*a[i][j+1]*temp);
                    }
                }
            }
        }
    }
    
    for(int k=0;k<=((n+m-1)*30);k++)
    {
        ans=min(ans,dp[n][m][k]-k*k);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
		scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=((n+m-1)*30);k++)
                {
                    dp[i][j][k]=inf;
                }
            }
        }     
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        ans=inf;
		solve();
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
