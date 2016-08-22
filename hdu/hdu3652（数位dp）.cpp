#include<iostream>
using namespace std;
int dp[10][10];
void init()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(!(j==1&&k==3))
				{
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		
	}
	return 0;
}
