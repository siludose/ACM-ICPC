/*

 题意是输入一个有向图，
其中有两个问题：一个是问需要向多少个学校发送软件，这样大家就都有
                （缩点信徒的入度为0的点的个数）
                还有一个是问需添加多少条边才能改图变为连通图
                （即入度为0和出度为0的个数的最大值）
这道题没有什么坑点，套用kuangbin的模板再建新图就可以
 */#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
const int maxn=150;
const int maxm=20010;
struct Edge
{
    int to;
    int next;
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],stack[maxn],belong[maxn];
int index,top,scc;
bool instack[maxn];
int num[maxn];
int in[maxn],out[maxn];
int n,x;
bool map[maxn][maxn];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[u]>low[v])low[u]=low[v];//已经理解
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])//如果相等，说明这个点是强连通分量中的一个点， 
    {                      //此时栈中的点构成强连通分量
        scc++;
        do
        {
            v=stack[--top];
            instack[v]=false;
            belong[v]=scc;
            num[scc]++;
        }while(v!=u);
    }
}

void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    memset(instack,0,sizeof(instack));
    index=top=scc=0;
    for(int i=1;i<=N;i++)
        if(!dfn[i])
            tarjan(i);
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(map, 0, sizeof(map));
}
void make_new_map()
{
    for(int i=1;i<=n;i++)
		for (int j = head[i]; j != -1; j = edge[j].next)
		{
			if (belong[i] != belong[edge[j].to]) {
				map[belong[i]][belong[edge[j].to]] = true;
			}
		}//这就是建新图的核心代码
        //如果不属于同一个联通分块，那么就使得这条边成立
        //由于题目的复杂度不高，可以使用连接矩阵，
        //而且使用连接矩阵的话可以进行判重
			

    for(int i=1;i<=scc;i++)
		for (int j = 1; j <= scc; j++)
			if (map[i][j]){
				out[i]++;
				in[j]++;
			}
}
void get_answer()
{
    int an1=0;
    for(int i=1;i<=scc;i++)
        if(in[i]==0)
            an1++;
    int an2=0;
    for(int i=1;i<=scc;i++)
        if(out[i]==0)
            an2++;
    printf("%d\n%d\n",an1,max(an1,an2));
}

int main()
{
	//freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=1;i<=n;)
        {
			scanf("%d", &x);
			if (x != 0)
				addedge(i, x);
			else
				i++;
        }       
        solve(n);
		make_new_map();
		if (scc == 1)
		{
			printf("%d\n%d\n", 1, 0); continue;
		}
		get_answer();
    }
    return 0;
}
