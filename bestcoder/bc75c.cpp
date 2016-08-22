#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define maxnum 1000000007
ll t,n,ans;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=1;
		scanf("%d",n);
		if(n%4==0)
		{
			for(int i=0;i<n/4;i++)
			{
				ans=(456950*ans)%maxnum;
			}
		}
		else
		{
			for(int i=0;i<n/4;i++)
			{
				ans=(456950*ans)%maxnum;
			}
			ans=(456950*ans*(n%4))%maxnum;
		} 
		printf("%d\n",ans);
	}	
	return 0;
}
