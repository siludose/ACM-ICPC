#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 1010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int a[maxn<<2];
int t,n,q,x,y;
void pushup(int rt)
{
    a[rt]=max(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&a[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int query(int l,int r,int rt,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return a[rt];
    }
    int m=(l+r)>>1;
    int ans=0;
    if(m>=L)
        ans=max(ans,query(lson,L,R));
    if(m<R)
        ans=max(ans,query(rson,L,R));
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,n,1,x,y));
        }
    }
    return 0;
}

