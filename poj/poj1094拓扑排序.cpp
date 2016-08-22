#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define maxn 30
int n,m,temp;
char s[5];
int val[maxn];
vector<int> to[maxn];
int que[maxn];
queue<int> q;
void Init()
{ 
	for (int i = 0; i < n; i++)
	{
		val[i] = que[i] = 0;
		if(to[i].size() != 0)
		{
			to[i].clear();
		}
	}
	que[n] = 0;
}
void init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<to[i].size();j++)
		{
			val[to[i][j]]++;
		}
	}
} 
int toposort(int n)
{
	bool button=true;
	for(int i=0;i<n;i++)
	{
		if(val[i]==0)
		{
			q.push(i);
		}
	}
	if(q.size()!=1)
	{
		button=false;
	}
	int res=0;
	while(!q.empty())
	{ 
		int goal=q.front();
		q.pop();
		que[res++]=goal;
		int count=0;
		for(int i=0;i<to[goal].size();i++)
		{			
			val[to[goal][i]]--;
			if(val[to[goal][i]]==0)
			{
				q.push(to[goal][i]);
				count++;
			}
			if(count>1)
			{
				button=false;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(val[i]>0)
		{
			return -1;
		}
	}
	if(button)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
	while(scanf("%d %d",&n,&m))
	{
		if (n + m == 0)
		{
			break;
		}
//		if(n==1&&m==0)
//		{
//			printf("Sorted sequence determined after %d relations: A.\n",0);
//			continue;
//		}
		if(n>m+1)
		{
			printf("Sorted sequence cannot be determined.\n");
			continue;
		}
		Init();
		int button=false;
		int count=0;
		temp = 1;
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			to[s[0]-'A'].push_back(s[2]-'A');
			val[s[2]-'A']++;
			if(button==false)
			{
				temp=toposort(n);
			}		
			if(button==false&&temp==-1)
			{
				count=i;
				button=true;
			}
			if(button==false&&temp==1)
			{
				count=i;
				button=true;
			}
			init();
		}
		if(temp==1)	
		{
			printf("Sorted sequence determined after %d relations: ",count+1);
			for(int i=0;i<n;i++)
			{
				printf("%c",que[i]+'A');
			}
			printf(".\n");
		}
		else if(temp==-1)
		{
			printf("Inconsistency found after %d relations.\n",count+1);
		}
		else
		{
			printf("Sorted sequence cannot be determined.\n");
		}	
	}
	return 0;
}
