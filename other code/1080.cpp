#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
const int maxn=110;

int t,len1,len2,dp[maxn][maxn],index1[maxn][5],index2[maxn][5];
int matrix[5][5]={{5,-1,-2,-1,-3},  
							{-1,5,-3,-2,-4},  
							{-2,-3,5,-2,-2},  
							{-1,-2,-2,5,-1},  
							{-3,-4,-2,-1,0}};
char s1[maxn],s2[maxn];
map<char,int>dictionary;
void LCS();
int main()
{
	dictionary['A']=0,dictionary['C']=1,dictionary['G']=2,dictionary['T'] = 3, dictionary['-'] = 4; 

	scanf("%d",&t);
	while(t--!=0)
	{
		scanf("%d %s",&len2,s1+1);
		scanf("%d %s",&len2,s2+1);
		LCS();
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
void LCS()
{
	dp[0][0]=0;
	for(int i=1;i<=len1;i++)
	{
		dp[i][0]=matrix[dictionary[s1[i]]][dictionary['-']]+dp[i-1][0];
	}
	for(int j=1;j<=len2;j++)
	{
		dp[0][j]=matrix[dictionary['-']][dictionary[s2[j]]]+dp[0][j-1];
	}
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
		{
			dp[i][j]=dp[i-1][j-1]+matrix[dictionary[s1[i]]][dictionary[s2[j]]];
			dp[i][j]=max(dp[i][j],matrix[dictionary[s1[i]]][dictionary['-']]);
			dp[i][j]=max(dp[i][j],matrix[dictionary['-']][dictionary[s2[j]]]);
		}
}