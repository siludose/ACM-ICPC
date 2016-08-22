#include<iostream>
#include<queue>
//#pragma warning(disable:4996)
using namespace std;
int t,w,h;
char map[45][45];
int dir[2][4][2] = { {{-1,0},{0,-1},{1,0},{0,1}},{{1,0},{0,-1},{-1,0},{0,1}} };
int num_step,min_step;
int if_free;
int if_right;
int si,sj,ei,ej;
bool flag;
bool vis[45][45];
queue<int>qi, qj;
int dis[45][45];
void dfs(int si,int sj,int direct)
{
	num_step++;
	bool button=true;
 	if(si==ei&&sj==ej)
	{
		if(min_step>num_step)
		{
			min_step=num_step;
		}
		if (if_free == 0)
		{
			flag = true;
		}
		return;
	}
	for(int i=direct;i<4+direct&&button&&(!flag);i++)
	{
		int newi=si+dir[if_right][i%4][0];
		int newj=sj+dir[if_right][i%4][1];
		if(newi>=1&&newj>=1&&newi<=w&&newj<=h)
		{
			if(map[newj][newi]!='#')
			{
				if(if_free==0)
				{
					button=false;
				}
				dfs(newi,newj,(i+3)%4);
				if (if_free == 1)
				{
					num_step--;
				}
			}
		}		
	}
}
void bfs(int si, int sj)
{
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[si][sj] = true;
	dis[si][sj] = 1;
	qi.push(si); qj.push(sj);
	while (!qi.empty())
	{
		int i = qi.front(); qi.pop();
		int j = qj.front(); qj.pop();

		for (int k = 0; k < 4;k++)
		{
			int newi = i + dir[0][k][0];
			int newj = j + dir[0][k][1];

			if (newi >= 1 && newj >= 1 && newi <= w&&newj <= h)
			{
				if (map[newj][newi] != '#' && (!vis[newi][newj]))
				{
					qi.push(newi);
					qj.push(newj);
					vis[newi][newj] = true;
					dis[newi][newj] = min(dis[newi][newj], dis[i][j] + 1);
				}
			}
		}
	}
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&w,&h);
        for(int i=1;i<=h;i++)
        {
            scanf("%s",map[i]+1);
        }
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				if(map[i][j]=='S')
				{
					si=j;sj=i;
				}
				if(map[i][j]=='E')
				{
					ei=j;ej=i;
				}
			}
		}
		num_step = 0;
		if_free = 0;
		if_right = 0;
		flag = false;
		dfs(si, sj, 0); cout << num_step;

		num_step = 0;
		if_free = 0;
		if_right = 1;
		flag = false;
		dfs(si, sj, 0); cout << " " << num_step;
		
		bfs(si,sj);cout<<" "<<dis[ei][ej]<<endl;		
    }

	return 0;
}
