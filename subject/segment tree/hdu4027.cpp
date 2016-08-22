#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100100;
ll num[maxn<<2];
void pushup(int rt)
{
    num[rt]=num[rt<<1]+num[rt<<1|1];
}
void build(int l,int r,int rt)
{
	num[rt] = 0;
    if(l==r){
        scanf("%lld",&num[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int l,int r,int rt,int L,int R)
{
    if(l==r){
        num[rt]=(int)sqrt(num[rt]*1.0);
        return;
    }
    if(l>=L&&r<=R&&((r-l+1)==num[rt]))
        return;
    int m=(l+r)>>1;
    if(m>=L)
        update(lson,L,R);
    if(m<R)
        update(rson,L,R);
    pushup(rt);
}
ll query(int l,int r,int rt,int L,int R)
{
    if(l>=L&&r<=R){
        return num[rt];
    }
    int m=(l+r)>>1;
    ll ans=0;
    if(m>=L)
        ans+=query(lson,L,R);
    if(m<R)
        ans+=query(rson,L,R);
    return ans;
}
//void debug(int l,int r,int rt)
//{
//	if(l==r)
//	{
//		printf("%d ",num[rt]);
//		return;
//	}
//	int m=(l+r)>>1;
//	debug(lson);
//	debug(rson);
//}
int main()
{
    //freopen("input.txt","r",stdin);
    int cas=0;
    int o,x,y,n,q;
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        build(1,n,1);
        scanf("%d",&q);
        printf("Case #%d:\n",cas);
        while(q--){
            scanf("%d%d%d",&o,&x,&y);
            //printf("%d %d %d\n",o,x,y);
			if (x > y)
				swap(x, y);
            if(o==1)
                printf("%lld\n",query(1,n,1,x,y));
            else if(o==0)
                update(1,n,1,x,y);
            //debug(1,n,1);printf("\n");
        }
		printf("\n");
    }
    return 0;
}
