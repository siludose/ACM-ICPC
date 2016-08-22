#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 222222
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1


int Max[maxn<<2];
int max(int a, int b)
{
	return a > b ? a : b;
}
void pushup(int rt)
{
    Max[rt] = max(Max[rt<<1] , Max[rt<<1|1]); 
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&Max[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int q,int l,int r,int rt)
{
    if(l==r)
    {
        Max[rt]=q;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
    {
        update(p,q,lson);
    }
    else
    {
        update(p,q,rson);
    }
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        return Max[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret=max(ret,query(L,R,lson));
    if(R>m)ret=max(ret,query(L,R,rson));
    return ret;
}
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
    {
        build(1,n,1);
        while(m--)
        {
			char c[2];int a, b;
            scanf("%s%d%d",c,&a,&b);
            if(c[0]=='Q')
            {
                printf("%d\n",query(a,b,1,n,1));
            }
            else
            {
                update(a,b,1,n,1);
            }
        }
    }
	
    return 0;
}