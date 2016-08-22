#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//#pragma warning(disable:4996)
#define maxn 5010
#define max(a,b) a>b?a:b
int n,m,op;
bool map[maxn][maxn];
struct Point
{
    int x;
    int y;
}p[maxn];
bool cmp(const Point &a,const Point &b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.y;
}

void solve()
{
    int res=-1;
    for(int i=0;i<op;i++)
    {
        for(int j=i+1;j<op;j++)
        {
            int dx=p[j].x-p[i].x;
            int dy=p[j].y-p[i].y;
            int tx=p[j].x;
            int ty=p[j].y;
            int ans=2;
            if(p[i].x-dx>=1&&p[i].x-dx<=n&&p[i].y-dy>=1&&p[i].y-dy<=m)
            	continue;
            while(tx+dx>=1&&tx+dx<=n&&ty+dy>=1&&ty+dy<=m)
            {
            	if(map[tx+dx][ty+dy])
            	{
            		tx+=dx;
            		ty+=dy;
            		ans++;
				}
				else
				{
					goto L;
				}
			}
			res=max(res,ans);
L:
			;
        }
    }
    if(res>=3)
    {
        printf("%d\n",res);
    }
    else
    {
        printf("%d\n",0);
    }
}
int main()
{
	freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);   	
    scanf("%d",&op);
    int a,b;

    for(int i=0;i<op;i++)
    {
        scanf("%d%d",&a,&b);
        p[i].x=a,p[i].y=b;
        map[a][b]=true;
    }
    sort(p,p+op,cmp);
    solve();

    return 0;
}
