#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<math.h>
using namespace std;
#define maxn 5100
#define maxx 1000100
#define ll long long
#define inf 0x3f3f3f3f
ll x[maxn],y[maxn];int dp[maxx];
int t,n,l,k;
int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x[i],&y[i]);
		}
			
		memset(dp,inf,sizeof(dp)) ; dp[x[1]]=0;
		for(int i=2;i<=n;i++)
		{
			l=sqrt(2*y[i]*y[1]*1.0-y[1]*y[1]);
			for(int j=max(x[1],x[i]-l);j<x[i];j++)
			{
				if(dp[j]==inf) continue;
				k=min(x[n],2*x[i]-j);
				dp[k]=min(dp[k],dp[j]+1);
			}
		}
		if(dp[x[n]]!=0x3f3f3f3f)
			printf("%d\n",dp[x[n]]);
		else
			printf("%d\n",-1);
	}
	return 0;
}
