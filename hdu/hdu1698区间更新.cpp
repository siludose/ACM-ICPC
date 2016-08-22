/*
1.记得向下标记
2.不能更新到树末，会超时
3.记得重置数组
*/
#include<iostream>
/*#pragma warning(disable:4996)*/
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100020
int t;
int n,q;
int sum[maxn << 2];
int col[maxn << 2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	col[rt] = 0;
	sum[rt] = 1;
    if(l==r)
    {
        return ;
    }
    int m=(r-l)/2+l;
    build(lson);
    build(rson);
}
void pushdown(int rt,int m)
{
	if (col[rt])//检查是否标记
	{
		col[rt << 1] = col[rt << 1 | 1] = col[rt];
		sum[rt<<1] = (m - (m >> 1))*col[rt];
		sum[rt << 1 | 1] = (m >> 1)*col[rt];
		col[rt] = 0;
	}
}
void insert(int l,int r,int rt,int L,int R,int n)
{
    if(l>=L&&r<=R)
    {
		col[rt] = n;
		sum[rt] = (r - l + 1)*n;
        return ;
    }
	pushdown(rt,r-l+1);
    int m=(r-l)/2+l;
    if(L<=m)
    {
        insert(lson,L,R,n);
    }
    if(R>m)
    {
        insert(rson,L,R,n);
    }
    pushup(rt);
}
int main()
{
/*	freopen("input.txt","r",stdin);*/
    scanf("%d",&t);
	int count = t;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        int x,y,z;
        build(1,n,1);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            insert(1,n,1,x,y,z);
        }
		printf("Case %d: The total value of the hook is %d.\n", count-t, sum[1]);
    }
    return 0;
}
