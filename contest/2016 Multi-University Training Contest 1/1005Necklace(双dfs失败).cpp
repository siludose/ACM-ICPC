#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 12
#define inf 0x3f3f3f3f
int n,m,temp,ans;
bool somber[maxn][maxn];
bool visyang[maxn];
bool visyin[maxn];
int a[maxn];
int number = 0;
void dfs2(int step)
{
    if(step==n)
    {
        if(temp<ans)
        {
            ans=temp;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visyang[i])
        {
			if (somber[i][a[step]] || somber[i][a[step + 1]])
				temp++;      
			if (temp >= ans)
			{
				if (somber[i][a[step]] || somber[i][a[step + 1]])
					temp--;
				return;
			}
				
			visyang[i] = true;
			dfs2( step + 1);
			if (somber[i][a[step]] || somber[i][a[step + 1]])
				temp--;
			visyang[i] = false;
        }     
    }
}
void dfs(int last,int step)
{
    if(step==n)
    {
        for(int i=1;i<=n;i++)
        {          
            temp=0;
            if(somber[i][a[1]]||somber[i][a[n]])
                temp++;
            if(temp>=ans)
                return;
			visyang[i] = true;
            dfs2(1);
            visyang[i]=false;
        }
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(!visyin[i])
        {
			visyin[i] = true; a[step+1] = i;
            dfs(i,step+1);
            visyin[i]=false;
        }
    }
}

int main()
{
    freopen("input.in","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
		if (n == 0||m==0)
		{
			printf("0\n"); continue;
		}
        int x,y;
        memset(somber,false,sizeof(somber));
        memset(a,0,sizeof(a));
        while(m--)
        {
            scanf("%d%d",&x,&y);
            somber[x][y]=true;
        }
        ans=n;
		a[1] = 1;
        for(int i=2;i<=n;i++)
        {
            visyin[i]=true;
			a[2] = i;
            dfs(i,2);
            visyin[i]=false;
        }
        printf("%d\n",ans);
    }
    return 0;
}
