#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 100100
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int t,n,k;
int a[100100];
int ma[maxn<<2],mi[maxn<<2];
void pushup(int rt)
{
	mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
	ma[rt] = max(ma[rt << 1], ma[rt << 1 | 1]);
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&ma[rt]);
		mi[rt]=ma[rt];
		return;	
	}	
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
} 
int querymi(int l,int r,int rt,int L,int R)
{
	if(l>=L&&r<=R)
	{
		return mi[rt];
	}
	int m=(l+r)>>1;
	if(m>=L&&m<R)
		return min(querymi(lson,L,R),querymi(rson,L,R));
	else if(m>=L)
		return querymi(lson,L,R);
	else if(m<R)
		return querymi(rson,L,R);
}
int queryma(int l,int r,int rt,int L,int R)
{
	if(l>=L&&r<=R)
	{
		return ma[rt];
	}
	int m=(l+r)>>1;
	if(m>=L&&m<R)
		return max(queryma(lson,L,R),queryma(rson,L,R));
	else if(m>=L)
		return queryma(lson,L,R);
	else if(m<R)
		return queryma(rson,L,R);
}
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		build(1,n,1);
		int sum=0;
		for(int i=1;i<n;i++)
		{
			int l=i,r=n;			
			while((l+1)<r)
			{
				int m=(l+r)>>1;
				if(queryma(1,n,1,i,m)-querymi(1,n,1,i,m)<k)
				{
					l=m;
				}
				else
				{
					r=m-1;
				}
			}
			if(queryma(1, n, 1, i, r) - querymi(1, n, 1, i, r)<k)
				sum += r - i;
			else
				sum += l - i;
		}
		printf("%d\n",sum+n);
	}
	return 0;
}
