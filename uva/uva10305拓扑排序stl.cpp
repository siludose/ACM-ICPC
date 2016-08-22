#include<iostream>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
#define maxn 110
int val[maxn];
int to[maxn];
int m,n;
int u,v;
queue<int> que;

void toposort()
{
	int count=0;
	while(count!=m)
	{
		for(int i=1;i<=m;i++)
		{
			if(val[i]==0)
			{
				val[i]=-1;
				val[to[i]]--;
				que.push(i);
				count++;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	while(~scanf("%d %d",&m,&n)&&(m||n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			val[u]++;
			to[v]=u;
		}
		toposort();
		printf("%d",que.front());
		que.pop();
		while(!que.empty())
		{
			printf(" %d",que.front());
			que.pop(); 
		}
	}
	return 0;
} 
