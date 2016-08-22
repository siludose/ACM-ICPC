#include<iostream>
using namespace std;
int c,g;
int dp[22][15000];
int x[22],v[22];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&c,&g);
    for(int i=1;i<=c;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=g;i++)
    {
        scanf("%d",&v[i]);
    }
    dp[0][7500]=1;
    for(int i=1;i<=g;i++)
    {
        for(int j=0;j<=15000;j++)
        {
            if(dp[i-1][j])
            {
                for(int k=1;k<=c;k++)
                {
                    dp[i][j+v[i]*x[k]]+=dp[i-1][j];
                }
            }
        }
    }
    printf("%d\n",dp[g][7500]);
    return 0;
}
