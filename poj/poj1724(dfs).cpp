#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
#define maxn 110
int k,n,m;
int a,b,c,d;
int theend[maxn];
int thestart[maxn];
int shortest;
bool vis[maxn];
struct Node
{
	int to;
	int le;
	int co;
	int next;
}node[maxn*maxn+10000];
void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		thestart[i]=-1;
		theend[i]=-1;
	}
}
void dfs(int rt,int len,int cost)
{
	if(cost>k)
	{
		return;
	}
	if(len>shortest)
	{
		return;
	}
    if(rt==n)
    {
        shortest=min(shortest,len);
        return;
    }
    for(int i=thestart[rt];i!=-1;i=node[i].next)
    {
    	int nex=node[i].to;
    	if(!vis[nex])
    	{
    		vis[nex]=true;
    		dfs(nex,len+node[i].le,cost+node[i].co);
    		vis[nex]=false;
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
    while(~scanf("%d%d%d",&k,&n,&m))
    {
    	init(n);
    	int num=0;
    	while(m--)
	    {
	        scanf("%d%d%d%d",&a,&b,&c,&d);	        
	        node[++num].to=b;
	        node[num].le=c;
	        node[num].co=d;
	        node[num].next=-1;
	        if(theend[a]==-1)
	        {
	        	thestart[a]=num;
			}
			else
			{
				node[theend[a]].next=num;
			}
			theend[a]=num;
	    }
	    shortest=0x7fffffff;
	    dfs(1,0,0);
	    if(shortest==0x7fffffff)
	    {
	        printf("-1\n");
	    }
	    else
	    {
	        printf("%d",shortest);
	    }
	}   
    return 0;
}
