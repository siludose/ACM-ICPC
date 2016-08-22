/*
    这道题如果仅仅是求桥的数量的话就真的太套路了，
    它还要求输入哪些边是桥
    斌哥的模板是有对边进行标记的
    由于要按照顺序输出，所以注意在查边的时候，看是不是左边的点小于右边的点
 */

//处理重边
map<int,int>mapit;
inline bool isHash(int u,int v)
{
    if(mapit[u*MAXN+v])return true;
    if(mapit[v*MAXN+u])return true;
    mapit[u*MAXN+v] = mapit[v*MAXN+u] = 1;
    return false;
}
//这是处理重边的好方法，每次查询和放入都是O（logN）

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define maxn 105
#define maxm 100100
struct Edge
{
    int to,next;
    bool cut;//增加了这个
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
bool cut[maxn];
int add_block[maxn];
int bridge;
int n,u,v;
char ch;
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=false;
    head[u]=tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    int son=0;//判断是否为割点需要用到
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)continue;
        if(!dfn[v])
        {
            son++;
            Tarjan(v,u);
            if(low[v]<low[u])low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
            if(u!=pre&&low[v]>=dfn[u])
            {
                cut[u]=true;
                add_block[u]++;
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(u==pre&&son>1)cut[u]=true;
    if(u==pre)add_block[u]=son-1;
    Instack[u]=false;
    top--;
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(Instack,0,sizeof(Instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,0,sizeof(cut));
    Index=top=0;
    bridge=0;
    
    for(int i=1;i<=N;i++)
        if(!dfn[i])
            Tarjan(i,i);
    printf("%d critical links\n",bridge);
    vector< pair<int,int> >ans;
    for(int u=1;u<=N;u++)
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cut&&edge[i].to>u)
                ans.push_back(make_pair(u,edge[i].to));//答案存储在vector中
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
    printf("\n");
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        init();
        int u,k,v;
        for(int i=1;i<=n;i++)
        {
            scanf("%d (%d)",&u,&k);
            u++;
            
            while(k--)
            {
                scanf("%d",&v);
                v++;
                if(v<=u)continue;
                addedge(u,v);
                addedge(v,u);
            }
        }
        solve(n);
    }
    return 0;
}
