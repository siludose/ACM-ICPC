#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 1000010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int v[maxn<<2],c[maxn<<2],n,m;
bool same[maxn << 2];
bool setv[maxn << 2];
char s[10];
bool ak47[10000];
void play_table()
{
	for (int i = 0; i < 10000; i++)
	{
		int num = i;
		bool button = false;
		while (num > 0)
		{
			if (!((num % 10 == 4) || (num % 10 == 7)))
			{
				button = false;
				break;
			}
			num /= 10;
			button = true;
		}
		if (button)ak47[i] = true;
		else ak47[i] = false;
	}
}
void pushup(int rt)
{
	c[rt]=c[rt<<1]+c[rt<<1|1];
	if (v[rt << 1] == v[rt << 1 | 1]&&same[rt<<1]&&same[rt<<1|1])
	{
		same[rt] = true;
		v[rt] = v[rt << 1];
	}
}
void pushdown(int rt,int l,int r)
{
	same[rt<<1]=same[rt<<1|1]=same[rt];
	v[rt << 1] = v[rt << 1 | 1] = v[rt];
	if (c[rt] == 0)
		c[rt << 1] = c[rt << 1 | 1] = 0;
	else
	{
		int m = (l + r) >> 1;
		c[rt << 1] = m - l + 1;
		c[rt << 1 | 1] = r - m;
	}		
}
void build(int l,int r,int rt)
{

	if(l==r)
	{
		same[rt] = true;
		scanf("%d",&v[rt]);
		if (ak47[v[rt]])
			c[rt] = 1;
		else
			c[rt] = 0;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void add(int l,int r,int rt,int L,int R,int a)
{
	if(l >= L&&r <= R&&same[rt])
	{
		setv[rt] = true;
		v[rt]+=a;
		if (ak47[v[rt]])
			c[rt] = r-l+1;
		else
			c[rt] = 0;
		return;
	}
	if (setv[rt])
	{
		pushdown(rt, l, r);
	}
	int m=(l+r)>>1;
	if(m>=L)add(lson,L,R,a);
	if(m<R)add(rson,L,R,a);
	pushup(rt);
}
int query(int l,int r,int rt,int L,int R)
{
	int ans=0;
	if(l>=L&&r<=R)
	{
		return c[rt];
	}
	if (setv[rt])
	{
		pushdown(rt, l, r);
	}
	int m=(l+r)>>1;
	if(m>=L)ans+=query(lson,L,R);
	if(m<R)ans+=query(rson,L,R);
	return ans;
}
int main()
{
	freopen("data01.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	play_table();
	build(1,n,1);
	while(m--)
	{
		scanf("%s",s);
		int l,r,a;
		if(s[0]=='c')
		{
			scanf("%d%d",&l,&r);
			int ans=query(1,n,1,l,r);
			if(ans==1000000)
			{
				getchar();
			}
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&a);
			add(1,n,1,l,r,a);
		}
	}
	return 0;
}
