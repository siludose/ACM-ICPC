#include<iostream>
using namespace std;
int n;
int main(int i,int j)
{
	while(cin>>n)
	{
		char *s1=new char[n+1];
		char *s2=new char[n+1];
		
		int **dp=new int*[n+1];
		dp[0]=new int[n+1];
		dp[1]=new int[n+1];
		dp[0][0]=dp[1][0]=0;
		
		for(i=1,j=n;i<=n;i++,j--)
		{
			dp[0][i]=dp[1][i]=0;
			
			char temp;
			cin>>temp;
			s1[i]=s2[j]=temp;		
		}
		
		int maxlen=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(s1[i]==s2[j])
				{
					dp[i%2][j]=dp[(i-1)%2][j-1]+1;
				}
				else
				{
					dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
				}
				if(dp[i%2][j]>maxlen)
				{
					maxlen=dp[i%2][j];
				}
			}
		}
		cout<<n-maxlen<<endl;
		delete s2;
		delete s1;
		delete[] dp;
	}
	return 0;
}
