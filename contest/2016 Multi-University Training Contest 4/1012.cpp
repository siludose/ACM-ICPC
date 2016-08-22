#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 100100
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int t,n;
int sum[maxn<<2];
int a[maxn];
int b[maxn];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void update(int l,int r,int rt,int index)
{   
    if(l==r)
    {
        sum[rt]++;
        return;
    }
	int m=(l+r)>>1;
    if(m>=index)
        update(lson,index);
    if(m<index)
        update(rson,index);
    pushup(rt);
}
int query(int l,int r,int rt,int L,int R)
{
    int ans=0;
    if(l>=L&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    if(m>=L)
        ans+=query(lson,L,R);
    if(m<R)
        ans+=query(rson,L,R);
    return ans;
}
void build(int l, int r, int rt)
{
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
	int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	int countt = 0;
	while (t--)
	{
		scanf("%d", &n);
		build(1,n,1);
		for (int i = 0; i < n;i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i =n-1; i >=0; i--)
		{
			int num=query(1,n,1,a[i],n);
			b[a[i]] = abs(n - num-min(i+1,a[i]));
			update(1, n, 1, a[i]);
		}
		printf("Case #%d:", ++countt);
		for (int i = 1; i <= n; i++)
		{
			printf(" %d", b[i]);
		}
		printf("\n");
	}
    return 0;
}