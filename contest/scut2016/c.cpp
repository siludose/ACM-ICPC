#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
#define maxn 10
int n,m;
int ma[maxn][maxn];
int mp[maxn][maxn];
int ans;
bool vis[maxn][maxn];
int dp[8][1 << 18];
void dfs(int rt,int temp,int cost)
{
	if (rt >= 2)
	{
		if((temp&(1<<(rt-1)))||(temp&(1<<(rt+1))))
	}
	for (int i = 0; i < rt; i++)
	{
		if ((temp&(1 << i))>0)
		{
			dfs(rt + 1, temp | (1 << i), cost + mp[rt][i]);
		}
	}
	for()
}
int main()
{
	freopen("input.txt","r",stdin);
	int count=0;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&ma[i][j]);
            }
        }
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = 0; j < i; j++)
			{
				mp[i][j] = ma[i][j];
			}
			int te = i - 1;
			while (te >= 0)
			{
				mp[i][j++] = ma[te][i];
			}
		}
    }
    return 0;
}
