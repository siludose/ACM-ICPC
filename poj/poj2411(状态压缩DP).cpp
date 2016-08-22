#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define maxn 15
#define ll long long
int n,m;
int ta;
int path[15000][2];
ll dp[13][2100];

void dfs(int l,int now,int pre)
{
    if(l>m)return;
    if(l==m)
    {
        path[ta][0]=pre;
        path[ta++][1]=now;
        return;
    }
    dfs(l+2,(now<<2)|3,(pre<<2)|3);
    dfs(l+1,(now<<1)|1,pre<<1);
    dfs(l+1,now<<1,(pre<<1)|1);
}
int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m),n+m)
    {
        if(n<m){int t=n;n=m;m=t;}
        ta=0;
        dfs(0,0,0);
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ta;j++)
            {
                dp[i+1][path[j][1]]+=dp[i][path[j][0]];
            }
        }
        printf("%I64d\n",dp[n][(1<<m)-1]);
    }
    return 0;
}
