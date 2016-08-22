#include<iostream>
#include<vector>
#include<stack>
#define maxn 3100
#define inf 0x3f3f3f3f
using namespace std;
int n,m,u,v;
int val[maxn];
int cost[maxn][maxn];
int lowcost[maxn];
vector<int> to[maxn];
stack<int>st;
bool vis[maxn];

void dijkstar(int beg)
{
    for(int i=0;i<n;i++)
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
int findring()
{
    bool button=true;
    while(button)
    {
        button=false;
        for(int i=1;i<=n;i++)
        {
            if(val[i]==0&&(!vis[i]))
            {              
                st.push(i);
                vis[i]=true;
                button=true;
                for(int k=0;k<to[i].size();k++)
                {
                    val[to[i][k]]--;
                }
            }
        }
    }
    int mark;
    for(int i=1;i<=n;i++)
    {
        if(val[i]>0)
        {
            mark=i;
            for(int k=0;k<to[i].size();k++)
            {
                cost[i][to[i][k]]=0;
            }
        }
    }
    return mark;  
}

int main()
{
    freopen("input.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            val[u]++;
            val[v]++;
            to[v].push_back(u);
            to[u].push_back(v);
            cost[u][v]=1;
            cost[v][u]=1;
        }
        dijkstar(findring());
        for(int i=1;i<=n;i++)
        {
            printf("%d ",lowcost[i]);
        }
    }
    return 0;
}
