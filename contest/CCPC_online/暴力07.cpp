#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m;
int use[30];
char map[10][10];
int num[10][10];
int ans;
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		int flag=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(map[i][j]=='X')
				{
					int temp=num[i][j];
					if(temp>=num[i-1][j]||temp>=num[i][j-1]||temp>=num[i+1][j]||temp>=num[i][j+1])
					{
						flag=false;break;
					}
				}
				else if(map[i][j]=='.')
				{
					int temp=num[i][j];
					if(temp>=num[i-1][j]&&temp>=num[i][j-1]&&num[i+1][j]&&num[i][j+1])
					{
						flag=false;break;
					}
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(flag)
		{
			ans++;return;
		}			
	}	
	else
	{
		for(int i=1;i<=(n*m);i++)
		{
			if(!use[i])
			{
				num[x][y]=i;
				use[i]=true;
				if(y==m)
				{
					x++;y=1;
				}
				else
					y++;
				dfs(x,y);
				use[i]=false;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	memset(num,0x7f,sizeof(num));
	while(cin>>n>>m)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",map[i]+1);
		}
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}
