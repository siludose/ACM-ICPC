#include<iostream>
#include<cstdio>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 1050000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
ll sum[maxn<<2];
ll n,o;
ll add[maxn<<2];
void pushup(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(ll rt,ll m)
{
	if (add[rt])
	{
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += (m - (m >> 1))*add[rt];
		sum[rt << 1 | 1] += (m >> 1)*add[rt];
		add[rt] = 0;
	}
}
void update(ll l,ll r,ll rt,ll L,ll R,ll v)
{	
    if(l>=L&&r<=R)
    {
        sum[rt]+=v*(r-l+1);
		add[rt] += v;
		return;
    }
	pushdown(rt, r - l + 1);
    ll m=(l+r)>>1;
    if(m>=L)
        update(lson,L,R,v);
    if(m<R)
        update(rson,L,R,v);
	pushup(rt);
}
ll query(ll l,ll r,ll rt,ll L,ll R)
{
    ll ans=0;
    if(l>=L&&r<=R)
    {
        return sum[rt];
    }
	pushdown(rt, r - l + 1);
    ll m=(l+r)>>1;
    if(m>=L)
        ans+=query(lson,L,R);
    if(m<R)
        ans+=query(rson,L,R);
    return ans;
}
void build(ll l,ll r,ll rt)
{
	add[rt] = 0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&o))
    {
        build(1,n,1);
		char oper[3]; ll L, R;ll value;
        while(o--)
        {
            scanf("%s",oper);
            if(oper[0]=='Q')
            {
                scanf("%lld %lld",&L,&R);
                printf("%lld\n",query(1,n,1,L,R));
            }
            else if(oper[0]=='C')
            {
                scanf("%lld %lld %lld",&L,&R,&value);
                update(1,n,1,L,R,value);
            }
        }
        
    }
}
