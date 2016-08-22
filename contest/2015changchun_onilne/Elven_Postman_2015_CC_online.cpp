#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
#define maxn 1010
int t,q,n;
struct P
{
    int v;
    int l;
    int r;
}p[maxn<<2];
void init()
{
    for(int i=0;i<maxn<<2;i++)
    {
        p[i].l=-1;
        p[i].r=-1;
        p[i].v=-1;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i].v);            
        }
        for(int i=1;i<n;i++)
        {
            int x=p[i].v;
            int rt=0;
            while(1)
            {
                if(p[rt].v>x)
                {
                    if(p[rt].r==-1)
                        {p[rt].r=i;break;}
                    else
                        rt=p[rt].r;
                }
                else
                {
                    if(p[rt].l==-1)
                        {p[rt].l=i;break;}
                    else
                        rt=p[rt].l;
                }
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            int x;
            scanf("%d",&x);
            int rt=0;
            while(1)
            {
                if(p[rt].v==x)
                {
                    printf("\n");break;
                }
                else if(p[rt].v>x)
                {
                    printf("E");rt=p[rt].r;
                }
                else
                {
                    printf("W");rt=p[rt].l;
                }
            }
        }
    }
}