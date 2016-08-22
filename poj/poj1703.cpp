#include<iostream>
#define maxn 200100
uisng namespace std;
int t,n,m;
char oper[3],a,b;
int pre[200100];
int high[200100];
void init(const int &n)
{
    for(int i=0;i<=n;i++)
    {
        pre[i]=i;
        high[i]=0;
    }
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
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%s",oper);
            scanf("%d%d",&a,&b);
            if(oper[0]=='A')
            {
                if(find(a)==find(b))
                {
                    printf("\n");
                }
                else if(find(a)==find(b))
                {
                    printf("\n");
                }
                else
                {
                    printf("\n");
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