/*题意没什么好说的，
不删边的话也没什么好说的
就是水题一道
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
#define maxn 1010
int t,n;
struct aa
{
	int num;
	int index;
}a[maxn];
int dp[maxn];
bool v[maxn][maxn];
bool vis[maxn];
bool cmp(struct aa a,struct aa b)
{
	return a.num<b.num;
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].num);   
			a[i].index=i;        
            sum+=a[i].num;
        }
        sort(a,a+n,cmp);
        int ii;
        for(ii=0;ii<n;ii++)
        {
            if(a[ii].num>ii)
			{
				break;
			}
		}
		if(ii!=n)
		{
			printf("Case #%d: No\n", cas); continue;
		}
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(a[i].num==0)
            	continue;
            for(int k=a[i].num-1;k>=0;k--)
            {
				v[i][k] = true;
			}
		}
		printf("Case #%d: Yes\n",cas);
		printf("%d\n", sum);
		for(int i=0;i<n;i++)
		{
			for (int k = 0; k < n; k++)
			{
				if (v[i][k])
				{
					printf("%d %d\n", a[i].index+1, a[k].index+1);
				}
			}
		}
		memset(v, 0, sizeof(v));
    }
    
    return 0;
}
