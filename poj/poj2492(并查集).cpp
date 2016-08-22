#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 2100
int t,n,m,a,b;
int pre[maxn];
int high[maxn];
bool flag;
void init(const int &n)
{
    for(int i=0;i<=n;i++)
    {
        pre[i]=i;
        high[i]=0;
    }
    flag=true;
}
int find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void add(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if (high[x]<high[y])
    {
        pre[x]=y;
    }
    else
    {
        pre[x]=y;
        if(high[x]==high[y])
        {
            high[x]++;
        }
    }
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    int count=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init(n*2);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b)&&flag)
            {
                flag=false;
                printf("Scenario #%d:\n",++count);
                printf("Suspicious bugs found!\n");
            }
            add(a,b+n);
            add(a+n,b);
        }
        if(flag)
		{
			printf("Scenario #%d:\n",++count);
            printf("No suspicious bugs found!\n");
		}
        if(t!=0)printf("\n");
    }
    return 0;
}
