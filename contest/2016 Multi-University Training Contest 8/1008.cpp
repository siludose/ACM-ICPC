#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include<string.h>
using namespace std;
#define maxn 100100
#define inf 0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
ll t,n,q,o,x,y,z;
ll sum[maxn<<2];
ll mi[maxn << 2];
ll ma[maxn << 2];
ll add[maxn<<2];
void pushup(ll rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
	ma[rt] = max(ma[rt << 1], ma[rt << 1 | 1]);
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
void build(ll l,ll r,ll rt)
{
    add[rt] = 0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
		mi[rt] = ma[rt] = sum[rt];
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
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
void update2(ll l,ll r,ll rt,ll L,ll R)
{
	if (l == r)
	{
		sum[rt] = (ll)sqrt(sum[rt] * 1.0); return;
	}
	if (l >= L&&r <= R && (mi[rt] == ma[rt]))
	{
		ll num = (ll)sqrt(mi[rt] * 1.0);
		update(1, n, 1, l, r, -(mi[rt] - num));
		return;
	}
    pushdown(rt, r - l + 1);
    ll m=(l+r)>>1;
	if (m >= L)
	{
		update2(lson, L, R);
	}      
	if (m < R)
	{
		update2(rson, L, R);
	}	
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
int main()
{
    freopen("input.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        build(1,n,1);
        while(q--)
        {
            scanf("%lld",&o);
            if(o==1)
            {
                scanf("%lld%lld%lld",&x,&y,&z);
                update(1,n,1,x,y,z);
            }
            else if(o==2)
            {
                scanf("%lld%lld",&x,&y);
                update2(1,n,1,x,y);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",query(1,n,1,x,y));
            }
        }
    }
    return 0;
}