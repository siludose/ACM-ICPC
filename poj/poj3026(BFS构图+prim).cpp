#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 300
#define inf 0x3f3f3f3f
int t,n,m,ns,spcial_num;
char tmp[maxn];
char map[maxn][maxn];
int dist[maxn][maxn];
int node[maxn][maxn];
int num[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
typedef struct Point
{
    int r,l;
    Point(int r_,int l_):r(r_),l(l_){}
}point;
void bfs(int sx,int sy)
{
    queue<Point> Q;

    memset(vis,false,sizeof(vis));
    vis[sx][sy]=true;
    Q.push(Point(sx,sy));
    dist[sx][sy]=0;

    while(!Q.empty())
    {
        point e=Q.front();Q.pop();
        int x=e.r,y=e.l;
        if(map[x][y]=='A'||map[x][y]=='S')
        {
            node[num[sx][sy]][num[x][y]]=dist[x][y];
        }
        for(int d=0;d<4;d++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0||ny<0||nx>=n||ny>=m)
                continue;
            if(vis[nx][ny]||map[nx][ny]=='#')
                continue;
            vis[nx][ny]=true;
            dist[nx][ny]=dist[x][y]+1;
            Q.push(Point(nx,ny));
        }
    }
}
int prim()
{
    int lowc[maxn];
    bool vis[maxn];
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[ns]=true;
    for(int i=0;i<spcial_num;i++)
        lowc[i]=node[ns][i];
    for(int i=1;i<spcial_num;i++)
    {
        int minc=inf;
        int p=-1;
        for(int j=0;j<spcial_num;j++)
        {
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==inf)return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<spcial_num;j++)
        {
            if(!vis[j]&&lowc[j]>node[p][j])
            {
                lowc[j]=node[p][j];
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        spcial_num=0;
        scanf("%d%d",&m,&n);
		gets(tmp);
        for(int i=0;i<n;i++)
        {
			gets(map[i]);
		}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='A')
                {
                    num[i][j]=spcial_num++;
                }
                if(map[i][j]=='S')
                {
                    num[i][j]=spcial_num++;
                    ns=spcial_num-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='A'||map[i][j]=='S')
                {
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
