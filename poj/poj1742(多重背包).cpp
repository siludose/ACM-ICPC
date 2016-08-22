#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int n,m;
int a[150],c[150];
bool dp[100016];
int sum[100016];
int main()
{
	freopen("input.txt","r",stdin);
    while(cin>>n>>m&&n>0)
    {
		memset(dp, 0, sizeof(dp));
    	for(int i=1;i<=n;i++)
	        scanf("%d",&a[i]);
	    for(int i=1;i<=n;i++)
	        scanf("%d",&c[i]);
	    dp[0]=true;
		int ans = 0;
	    for(int i = 1; i <= n; i++)
	    {
			memset(sum, 0, sizeof(sum));
	        for(int j = a[i]; j <= m; j++)
	        {
				if (!dp[j] && dp[j - a[i]] && sum[j - a[i]] < c[i])
				{
					dp[j] = true;
					sum[j] = sum[j - a[i]] + 1;
					ans++;
				}
	        }
	    }
	    printf("%d\n",ans);	
	}
    return 0;
}
