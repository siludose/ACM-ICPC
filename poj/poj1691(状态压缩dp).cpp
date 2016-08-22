#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 20
const int N = 1 << 16;
int t,n;
int map[maxn][maxn];
int col[maxn];
bool link[maxn][maxn];
int up[maxn];
int dp[N][maxn];
void init(int n)
{
    memset(link,0,sizeof(link));
    memset(col,0,sizeof(col));
    memset(dp,0x3f,sizeof(dp));
	memset(map, 0, sizeof(map));
	memset(up, 0, sizeof(up));
}
int min(int a, int b)
{
	if (a < b)return a;
	return b;
}
int main()
{	
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
		init(n);
        int a,b,c,d,e;
        for(int k=1;k<=n;k++)
        {
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            for(int i=a;i<=c;i++)
                for(int j=b;j<=d;j++)
                    map[i][j]=k;
            col[k]=e;
        } 

        for(int i=0;i<n-1;i++)
        {
			for (int j = 0; j < n; j++)
			{
				int from = map[i][j];
				int to = map[i + 1][j];
				if (to == 0 || from == 0)continue;
				if (from != to)
				{
					if (!link[from][to])
					{
						link[from][to] = true;
						up[to] |= (1 << from);
					}
				}
			}
        }
		for (int i = 1; i <= n; i++)
			if (up[i] == 0)
				dp[(1<<i)][col[i]] = 1;
			
		int maxans = 0;
        for(int i=1;i<=((1<<(n+1))-1);i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i&(1<<j))
					continue;
				if ((i&up[j]) != up[j])
					continue;
                for(int y=1;y<=20;y++)
                {
                    if(dp[i][y]==0x3f3f3f3f)continue;
					dp[i | (1 << j)][col[j]] = min(dp[i | (1 << j)][col[j]],dp[i][y] + (col[j] == y ? 0 : 1));
					/*if (dp[i | (1 << j)][col[j]] != 0x3f3f3f3f)
					{
						if (dp[i | (1 << j)][col[j]]>maxans)
							maxans = dp[i | (1 << j)][col[j]];
					}*/
                }   
            }
        }
        int ans=0x7fffffff;
        for(int i=0;i<=n;i++)
        {
            ans=min(ans,dp[(1<<(n+1))-2][i]);
        }
		cout << ans << endl; //cout << maxans << endl;
    }
    return 0;
}
