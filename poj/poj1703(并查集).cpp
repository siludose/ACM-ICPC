#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 100000 * 2 + 16
int t,n,m;
char oper[3];int a,b;
int pre[MAX_N];
int high[MAX_N];
void init(const int &n)
{
    for(int i=0;i<n;i++)
    {
        pre[i]=i;
        high[i]=0;
    }
}

int find(int x)
{
    int r=x;
    while(pre[r]!=r)
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
//	if(pre[x]==x)
//	{
//		return x;
//	}
//	else
//	{
//		return pre[x]=find(pre[x]);
//	}
}
void add(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if(high[x]<high[y])
    {
        pre[x]=y;
    }
    else
    {
        pre[y]=x;
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
    while(t--)
    {
        scanf("%d%d",&n,&m);
    	init(n*2);
        while(m--)
        {
            scanf("%s",oper);
            scanf("%d%d",&a,&b);
            if(oper[0]=='A')
            {
                if(find(a)==find(b))
                {
                    printf("In the same gang.\n");
                }
                else if(find(a)==find(b+n))
                {
                    printf("In different gangs.\n");
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
            else
            {
                add(a,b+n);
                add(a+n,b);
            }
        }
    }
    return 0;
}
