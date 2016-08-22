#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
const int maxn=100100;
int t,n,q;
ll sum[maxn<<2];
ll add[maxn<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	add[rt] = 0;
    if(l==r){
        sum[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1]=add[rt];
        add[rt<<1|1]=add[rt];
        sum[rt<<1]=(m-(m>>1))*add[rt];
        sum[rt<<1|1]=(m>>1)*add[rt];
        add[rt]=0;
    }  
}
void update(int l,int r,int rt,int L,int R,int v)
{
    if(l>=L&&r<=R){
        sum[rt]=(r-l+1)*v;
        add[rt]=v;
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(m>=L)
        update(lson,L,R,v);
    if(m<R)
        update(rson,L,R,v);
    pushup(rt);
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
	for (int cas = 1; cas <= t;cas++) {
        scanf("%d%d",&n,&q);
		build(1, n, 1);
        int x,y,v;
        while(q--){
            scanf("%d%d%d",&x,&y,&v);
            update(1,n,1,x,y,v);
        }
        printf("Case %d: The total value of the hook is %lld.\n",cas,sum[1]);
    }
    return 0;
}
