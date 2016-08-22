#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 110
#define inf 0x3f3f3f3f
int map[maxn][maxn];
int n,m,a,b;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				map[i][j]=inf;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%d%d",&a,&b);
				map[i][a]=b;
			}
		}
		floyd();
		int minans=inf,mark=0;
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				if(map[i][j]>ans)
				{
					ans=map[i][j];
				}
			}
			if(ans<minans)
			{
				minans=ans;
				mark=i;
			}
		}
		if(minans!=inf)
		{
			printf("%d %d\n",mark,minans);
		}
		else
		{
			printf("disjoint\n");
		}
	}
	return 0;
}
