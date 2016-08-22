#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define maxn 200010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
#define inf 201000
ll mi[maxn << 2];
ll ma[maxn << 2];
ll a[maxn];
ll sum[maxn << 2];
ll addd[maxn << 2];
ll addmi[maxn << 2];
ll addma[maxn << 2];
ll mmmi, mmma;
void pushup(ll rt)
{
	ma[rt] = max(ma[rt << 1], ma[rt << 1 | 1]);
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
void pushdownma(ll rt)
{
	if (addma[rt] != 0)
	{
		ma[rt << 1] = max(addma[rt], ma[rt << 1 ]);
		ma[rt << 1 | 1] = max(addma[rt], ma[rt << 1 | 1]);
		addma[rt] = 0;
	}
}
void pushdownmi(ll rt)
{
	if (addmi[rt] != 0)
	{
		mi[rt << 1] = min(addmi[rt], mi[rt << 1]);
		mi[rt << 1 | 1] = min(addmi[rt], mi[rt << 1 | 1]);
		addmi[rt] = 0;
	}
}
void update(ll l, ll r, ll rt, ll L, ll R, ll v)
{
	if (l >= L&&r <= R)
	{
		mi[rt] = min(mi[rt], v);
		ma[rt] = max(ma[rt], v);
		addmi[rt] = v; addma[rt] = v;
		return;
	}
	pushdownmi(rt); pushdownma(rt);
	ll m = (l + r) >> 1;
	if (m >= L)
		update(lson, L, R, v);
	if (m < R)
		update(rson, L, R, v);
	pushup(rt);
}
void query(ll l, ll r, ll rt, ll index)
{
	pushdownmi(rt); pushdownma(rt);
	if (l == r)
	{
		mmmi = mi[rt];
		mmma = ma[rt];
		return;
	}
	ll m = (l + r) >> 1;
	if (m >= index)
		query(lson, index);
	else
		query(rson, index);
	return;
}
void build(ll l, ll r, ll rt)
{
	addmi[rt] = 0;
	addma[rt] = 0;
	if (l == r)
	{
		mi[rt] = inf;
		ma[rt] = 0;
		return;
	}
	ll m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
void pushupp(ll rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdownn(ll rt, ll m)
{
	if (addd[rt])
	{
		addd[rt << 1] += addd[rt];
		addd[rt << 1 | 1] += addd[rt];
		sum[rt << 1] += (m - (m >> 1))*addd[rt];
		sum[rt << 1 | 1] += (m >> 1)*addd[rt];
		addd[rt] = 0;
	}
}
void updatee(ll l, ll r, ll rt, ll L, ll R, ll v)
{
	if (l >= L&&r <= R)
	{
		sum[rt] += v*(r - l + 1);
		addd[rt] += v;
		return;
	}
	pushdownn(rt, r - l + 1);
	ll m = (l + r) >> 1;
	if (m >= L)
		updatee(lson, L, R, v);
	if (m < R)
		updatee(rson, L, R, v);
	pushupp(rt);
}
ll queryy(ll l, ll r, ll rt, ll index)
{
	if (l == r)
	{
		return sum[rt];
	}
	pushdownn(rt, r - l + 1);
	ll m = (l + r) >> 1;
	if (m >= index)
		return queryy(lson, index);
	else
		return queryy(rson, index);
}
void buildd(ll l, ll r, ll rt)
{
	addd[rt] = 0;
	if (l == r)
	{
		sum[rt] = 0;
		return;
	}
	ll m = (l + r) >> 1;
	buildd(lson);
	buildd(rson);
	pushup(rt);
}

struct xxx
{
	ll zuo;
	ll you;
}xx[maxn];
int main()
{
	//freopen("input.txt","r",stdin);
	ll n, m;
	while (scanf("%lld%lld", &n, &m) != EOF&&n)
	{
		build(1, n - 1, 1);
		buildd(1, m, 1);
		for (int i = 1; i < n; i++)
			scanf("%lld", &a[i]);
		int x, y;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			if (x > y)swap(x, y);
			update(1, n - 1, 1, x, y - 1, i);
		}
		for (int i = 1; i < n; i++)
		{
			query(1, n - 1, 1, i);
			if (mmma == 0)
			{
				xx[i].zuo = -1;
				xx[i].you = -1;
			}
			else
			{
				xx[i].zuo = mmmi;
				xx[i].you = mmma;
			}
		}
		for (ll i = 1; i < n; i++)
		{
			if (xx[i].zuo == -1)continue;
			updatee(1, m, 1, xx[i].zuo, xx[i].you, a[i]);
		}
		for (ll i = 1; i <= m; i++)
		{
			printf("%lld\n", queryy(1, m, 1, i));
		}
	}
	return 0;
}