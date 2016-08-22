#include<iostream>
#include<string.h>
#define max 100010
using namespace std;
int n,max_money;
int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&max_money,&n))
    {
        int *num=new int[n+10];
        int *money=new int[n+10];
        int *dp=new int [max_money+10];
        int *count=new int[max_money+10];
        memset(dp,0,4*(max_money+10));
        memset(num,0,4*(n+10));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&num[i],&money[i]);
        }
        for(int i=0;i<n;i++)
        {
            memset(count,0,4*(max_money+10));
            for(int j=money[i];j<=max_money;j++)
            {
                if(dp[j]<dp[j-money[i]]+money[i]&&count[j-money[i]]<num[i])
                {
                    dp[j]=dp[j-money[i]]+money[i];
                    count[j]=count[j-money[i]]+1;
                }
            }           
        }
        printf("%d\n",dp[max_money]);
        delete num;
        delete money;
        delete dp;
        delete count;
    }
    return 0;
}
