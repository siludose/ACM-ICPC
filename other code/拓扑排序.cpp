#include<iostream>
#include<vector>
#include<queue>
#define maxn 110
using namespace std;
int n,m,u,v;
int val[maxn];
vector<int> to[maxn];
queue<int>que;
int toposort()
{
	int ans=0;
	bool button=true;
	while(button)
	{
		button=false;
		for(int i=1;i<=n;i++)
		{
			if(val[i]==1)
			{
				que.push(i);
				button=true;
			}
		}	
		while(!que.empty())
		{
			int temp=que.front();
			que.pop();
			val[temp]--;
			for(int i=0;i<to[temp].size();i++)
			{
				val[to[temp][i]]--;
			}
		}
		if(button)
			ans++;
	}
	return ans;
}
int main()
{
	//freopen("input.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			val[u]++;val[v]++;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		printf("%d\n",toposort());
	}
	return 0;
}
