#include<iostream>
#include<vector>
//#pragma warning(disable:4996)
#define maxn 3100
#define inf 0x3f3f3f3f
using namespace std;
int n,m,u,v;
int cost[maxn][maxn];//环中连接的两点为0，图中其他点为1
int lowcost[maxn];//记录最短路
vector<int> to[maxn];//记录边
bool vis[maxn];//是否已经访问
int color[maxn];//记录节点的状态，当其为1说明其在堆栈中
int pre[maxn];//记录堆栈的顺序
bool button;//用于找到环后跳出dfs
int beg;//记录dijkstar的起点
void dijkstar(int beg)
{
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=inf;vis[i]=false;
    }
    lowcost[beg]=0;
    for(int j=1;j<=n;j++)
    {
        int k=-1;
        int Min=inf;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&lowcost[i]<Min)
            {
                Min=lowcost[i];
                k=i;
            }
        }
        if(k==-1)break;
        vis[k]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i])
            {
                lowcost[i]=lowcost[k]+cost[k][i];
            }
    }
}
void dfs(int u)
{
    color[u]=1;
    for(int i=0;i<to[u].size();i++)
    {
        int v=to[u][i];
        if(color[v]==0&&button)
        {
            pre[v]=u;
            dfs(v);
        }
        if(color[v]==1&&button)
        {
            beg=v;
            cost[u][v]=0;cost[v][u]=0;
            int temp=u;
            while(1)
            {
                cost[temp][pre[temp]]=0;
                cost[pre[temp]][temp]=0;
                if(pre[temp]==v)
                {
                    break;
                }
                temp=pre[temp];
            }
            button=false;
            break;
        }
    }
    color[u]=2;
}
int main()
{
    //freopen("input.txt","r",stdin);
	
    while(cin>>n)
    {
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cost[i][j] = inf;
			}
		}
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            to[v].push_back(u);
            to[u].push_back(v);
            cost[u][v]=1;
            cost[v][u]=1;
        }
        button=true;
        dfs(1);
        dijkstar(beg);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",lowcost[i]);
        }
    }
    return 0;
}
