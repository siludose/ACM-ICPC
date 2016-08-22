#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
#define maxr 110
#define maxc 15
#define maxm 70
#define legal(x,y) x&y
int soldier[maxm];
int base[maxr];
int state[maxm];
int n,m,nums;
char s[maxr][maxc];
int dp[maxr][maxm][maxm];
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='H')
                {
                    base[i]+=(1<<j);
                }
            }
        }
        int nums=0;
        for(int i=0;i<(1<<m);i++)
        {
            if(legal(i,i<<1)||legal(i,i<<2))continue;
            int temp=i;
            while(temp)
            {
                soldier[nums]+=temp&1;
                temp=temp>>1;
            }
            state[nums++]=i;
           
    	}
        for(int i=0;i<nums;i++)
        {
            if(legal(state[i],base[0]))
                continue;
            dp[0][i][0]=soldier[i];
        }
        for(int i=0;i<nums;i++)
        {
            if(legal(state[i],base[1]))continue;
            for(int j=0;j<nums;j++)
            {
                if(legal(state[j],base[0]))continue;
                if(legal(state[i],state[j]))continue;
                dp[1][i][j]=max(dp[1][i][j],dp[0][j][0]+soldier[i]);
            }
        }
        for(int r=2;r<n;r++)
        {
            for(int i=0;i<nums;i++)
            {
                if(legal(state[i],base[r]))continue;
                for(int j=0;j<nums;j++)
                {
                    if(legal(state[j],base[r-1]))continue;
                    if(legal(state[i],state[j]))continue;
                    for(int k=0;k<nums;k++)
                    {
                        if(legal(state[k],base[r-2]))continue;
                        if(legal(state[k],state[i]))continue;
                        if(legal(state[k],state[j]))continue;
                        dp[r][i][j]=max(dp[r][i][j],dp[r-1][j][k]+soldier[i]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums;i++)
        {
            for(int j=0;j<nums;j++)
            {
                ans=max(ans,dp[n-1][i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
