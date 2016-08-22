#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=200010;
char s[MAXN];
int a[MAXN],mark[30];
int arr[MAXN],dp[MAXN];
int t;
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%s",s);
		int len=strlen(s);
		memset(mark,-1,sizeof(mark));
		int num=1;
		for(int i=0;i<len;i++)
		{
			int k=s[i]-'a'+1;
			if(mark[k]==-1)
			{
				mark[k]=num;
				a[i]=num;
				num++;
			}
			else
			{
				a[i]=mark[k];
			}
		}
		memset(arr, 0x7f, sizeof(arr));
		int x;
		int ans=0;
		for(int i=0;i<len;i++)
		{
			x=lower_bound(arr,arr+len,a[i])-arr;
			arr[x]=a[i];
			dp[i]=x+1;
		}
		for(int i=0;i<len;i++)
		{
			ans=max(ans,dp[i]);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
