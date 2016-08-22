#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <queue>  
#include <map>  
#include <set>  
#include <vector>  
#include <math.h>  
#include <bitset>  
#include <algorithm>  
#include <climits>  
using namespace std;

#define lson 2*i  
#define rson 2*i+1  
#define LS l,mid,lson  
#define RS mid+1,r,rson  
#define UP(i,x,y) for(i=x;i<=y;i++)  
#define DOWN(i,x,y) for(i=x;i>=y;i--)  
#define MEM(a,x) memset(a,x,sizeof(a))  
#define W(a) while(a)  
#define gcd(a,b) __gcd(a,b)  
#define LL long long  
#define N 500005  
#define MOD 1000000007  
#define INF 0x3f3f3f3f  
#define EXP 1e-8  
#define lowbit(x) (x&-x)  

LL s[N];
int n, m;
struct node
{
	int l, r, pre_r, suf_l;
	LL max_all, max_prefix, max_suffix, sum;
} a[N << 2];

void pushup(int l, int r, int i)
{
	int mid = (l + r) / 2;
	a[i].sum = a[lson].sum + a[rson].sum;//对应区间所有节点值的和

	a[i].max_prefix = a[lson].max_prefix;
	a[i].pre_r = a[lson].pre_r;
	a[i].max_suffix = a[rson].max_suffix;
	a[i].suf_l = a[rson].suf_l;
	//1.左边的sum+右区间的max_prefix;  
	a[i].max_all = a[lson].sum + a[rson].max_prefix;
	a[i].l = l;
	a[i].r = a[rson].pre_r;
	//2.左区间max_all  
	if (a[i].max_all < a[lson].max_all || (a[i].max_all == a[lson].max_all&&a[i].l == a[lson].l))
	{
		a[i].max_all = a[lson].max_all;
		a[i].l = a[lson].l;
		a[i].r = a[lson].r;
	}
	//3.左边的max_suffix+右边的max_prefix  
	if (a[i].max_all<a[lson].max_suffix + a[rson].max_prefix || (a[i].max_all == a[lson].max_suffix + a[rson].max_prefix &&a[i].l>a[lson].suf_l))
	{
		a[i].max_all = a[lson].max_suffix + a[rson].max_prefix;
		a[i].l = a[lson].suf_l;
		a[i].r = a[rson].pre_r;
	}
	//4.左边的max_suffix+右边的sum  
	if (a[i].max_all<a[lson].max_suffix + a[rson].sum || (a[i].max_all == a[lson].max_suffix + a[rson].sum &&a[i].l>a[lson].suf_l))
	{
		a[i].max_all = a[lson].max_suffix + a[rson].sum;
		a[i].l = a[lson].suf_l;
		a[i].r = r;
	}
	//5.右边的max_all  
	if (a[i].max_all<a[rson].max_all || (a[i].max_all == a[rson].max_all&&a[i].l>a[rson].suf_l))
	{
		a[i].max_all = a[rson].max_all;
		a[i].l = a[rson].l;
		a[i].r = a[rson].r;
	}
	//更新前缀与后缀的位置  
	if (a[lson].sum + a[rson].max_prefix > a[i].max_prefix)
	{
		a[i].max_prefix = a[lson].sum + a[rson].max_prefix;
		a[i].pre_r = a[rson].pre_r;
	}
	if (a[rson].sum + a[lson].max_suffix >= a[i].max_suffix)
	{
		a[i].max_suffix = a[rson].sum + a[lson].max_suffix;
		a[i].suf_l = a[lson].suf_l;
	}
}

void init(int l, int r, int i)
{
	if (l == r)
	{
		a[i].max_all = a[i].max_prefix = a[i].max_suffix = a[i].sum = s[l];
		a[i].l = a[i].r = a[i].pre_r = a[i].suf_l = l;
		return;
	}
	int mid = (l + r) / 2;
	init(LS);//递归到左边
	init(RS);//递归到右边
	pushup(l, r, i);//初始化非叶子节点
}

node query(int i, int l, int r, int L, int R)
{
	if (l == L&&r == R)
	{
		return a[i];
	}
	int mid = (L + R) >> 1;
	if (r <= mid)     return  query(lson, l, r, L, mid);
	else if (l > mid) return  query(rson, l, r, mid + 1, R);
	else
	{
		node t1 = query(lson, l, mid, L, mid);
		node t2 = query(rson, mid + 1, r, mid + 1, R);
		node t;
		t.sum = t1.sum + t2.sum;

		t.max_prefix = t1.max_prefix;
		t.pre_r = t1.pre_r;
		t.max_suffix = t2.max_suffix;
		t.suf_l = t2.suf_l;

		t.max_all = t1.sum + t2.max_prefix;
		t.l = l;
		t.r = t2.pre_r;


		if (t.max_all < t1.max_all || (t.max_all == t1.max_all&&t.l == t1.l))
		{
			t.max_all = t1.max_all;
			t.l = t1.l;
			t.r = t1.r;
		}
		if (t.max_all<t1.max_suffix + t2.max_prefix || (t.max_all == t1.max_suffix + t2.max_prefix &&t.l>t1.suf_l))
		{
			t.max_all = t1.max_suffix + t2.max_prefix;
			t.l = t1.suf_l;
			t.r = t2.pre_r;
		}
		if (t.max_all<t1.max_suffix + t2.sum || (t.max_all == t1.max_suffix + t2.sum &&t.l>t1.suf_l))
		{
			t.max_all = t1.max_suffix + t2.sum;
			t.l = t1.suf_l;
			t.r = t2.r;
		}
		if (t.max_all<t2.max_all || (t.max_all == t2.max_all&&t.l>t2.l))
		{
			t.max_all = t2.max_all;
			t.l = t2.l;
			t.r = t2.r;
		}

		if (t1.sum + t2.max_prefix > t.max_prefix)
		{
			t.max_prefix = t1.sum + t2.max_prefix;
			t.pre_r = t2.pre_r;
		}
		if (t2.sum + t1.max_suffix >= t.max_suffix)
		{
			t.max_suffix = t2.sum + t1.max_suffix;
			t.suf_l = t1.suf_l;
		}
		return t;
	}
}

int main()
{
	int i, j, l, r, cas = 1;
	while (~scanf("%d%d", &n, &m))
	{
		for (i = 1; i <= n; i++)
			scanf("%lld", &s[i]);
		init(1, n, 1);
		printf("Case %d:\n", cas++);
		while (m--)
		{
			scanf("%d%d", &l, &r);
			node t = query(1, l, r, 1, n);
			printf("%d %d\n", t.l, t.r);
		}
	}

	return 0;
}