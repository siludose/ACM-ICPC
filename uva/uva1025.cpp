#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxt 210
#define maxn 60
#define inf 0x3f3f3f3f
int dp[maxt][maxn];
bool has_train[maxt][maxn][2];
int n,T,m1,m2,cas,t[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
    cas=0;
    while(~scanf("%d",&n)&&n)
    {
    	memset(has_train,false,sizeof(has_train));
        scanf("%d",&T);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&t[i]);
        }
        scanf("%d",&m1);
        for(int i=1;i<=m1;i++)
        {
            int time;scanf("%d",&time);
            has_train[time][1][0]=true;
            for(int j=2;j<=n;j++)
            {
                time+=t[j-1];
                has_train[time][j][0]=true;
            }
        }
        scanf("%d",&m2);
        for(int i=1;i<=m2;i++)
        {
            int time;scanf("%d",&time);
            has_train[time][n][1]=true;
            for(int j=n-1;j>=1;j--)
            {
                time+=t[j];
                has_train[time][j][1]=true;
            }
        }
        for(int i=1;i<=n-1;i++)
            dp[T][i]=inf;
        dp[T][n]=0;
        for(int i=T-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n && has_train[i][j][0] && (i+t[j]<=T))
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1&&has_train[i][j][1]&&(i+t[j-1]<=T))
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }
        printf("Case Number %d: ",++cas);
        if(dp[0][1]>=inf)printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }
    return 0;
}
