#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
#include<cstdio>
#include<string>
#include<bitset>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=200100;
int mi[maxn<<2];
int ma[maxn<<2];
ll sum[maxn<<2];
int n,m;
const int xiao=0x3f3f3f3f;
const int da=0;
int mmmi,mmma;
ll a[maxn];
void pushup(int rt)
{
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
    ma[rt]=max(ma[rt<<1],ma[rt<<1|1]);
}
void add(int l,int r,int rt,int L,int R,int v)
{
    if(l==r)
    {
        mi[rt]=min(mi[rt],v);
        ma[rt]=max(ma[rt],v);
        return;
    }
    int m=(l+r)>>1;
    if(m>=L)
        add(lson,L,R,v);
    if(m<R)
        add(rson,L,R,v);
    pushup(rt);
}
void query(int l,int r,int rt,int index)
{
    if(l==r)
    {
        mmmi=mi[rt];
        mmma=ma[rt];
        return ;
    }
    int m=(l+r)>>1;
    if(m>=index)
        query(lson,index);
    else
        query(rson,index);
}
void init()
{
    memset(mi,0x3f,sizeof(mi));
    memset(ma,0,sizeof(ma));
    memset(sum,0,sizeof(sum));
}
void pushupp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void addd(int l,int r,int rt,int L,int R,int v)
{
    if(l==r)
    {
        sum[rt]+=v;
        return;
    }
    int m=(l+r)>>1;
    if(m>=L)
        addd(lson,L,R,v);
    if(m<R)
        addd(rson,L,R,v);
    pushupp(rt);
}
ll queryy(int l,int r,int rt,int index)
{
    if(l==r)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    if(m>=index)
        return queryy(lson,index);
    else
        return queryy(rson,index);
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<n;i++)
            scanf("%lld",&a[i]);
        int x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            if(x>y)
                swap(x,y);
            add(1,n-1,1,x,y-1,i);
        }
        for(int i=1;i<n;i++)
        {
            query(1,n-1,1,i);
            if(mmmi>mmma)continue;
            addd(1,m,1,mmmi,mmma,a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            printf("%lld\n",queryy(1,m,1,i));
        }
    }
    return 0;
}
