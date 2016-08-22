#include <iostream>
#include<algorithm>
#include <vector>
#include <math.h>
//#pragma warning(disable:4996)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn = 50000 + 16;
int N, Q, t;
int A_i[maxn];
struct Group
{
	int max;
	int cl;
	int cr;
}cow[maxn<<2];
void pushup(int rt)
{
	cow[rt].cl = cow[rt << 1].cl < cow[rt << 1 | 1].cl ? cow[rt << 1].cl : cow[rt << 1 | 1].cl;
	cow[rt].cr = cow[rt << 1].cr > cow[rt << 1 | 1].cr ? cow[rt << 1].cr : cow[rt << 1 | 1].cr;
}
void build(int l,int r,int rt)
{
	if (l == r)
	{
		cow[rt].cl = A_i[t];
		cow[rt].cr = A_i[t++];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
int query_l(int x, int  y, int l, int r, int rt)
{
	if (l>=x&&r<=y)
	{
		return cow[rt].cl;
	}
	int min_;
	int m = (l + r) >> 1;
	if (x > m)
		min_ = query_l(x, y, rson);
	else if (y <= m)
		min_ = query_l(x, y, lson);
	else
		min_ = min(query_l(x, y, rson), query_l(x, y, lson));
	return min_;	
}
int query_r(int x, int  y, int l, int r, int rt)
{
	if (l >= x&&r <= y)
	{
		return cow[rt].cr;
	}
	int max_;
	int m = (l + r) >> 1;
	if (x > m)
		max_ = query_r(x, y, rson);
	else if (y <= m)
		max_ = query_r(x, y, lson);
	else
		max_ = max(query_r(x, y, rson), query_r(x, y, lson));
	return max_;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A_i[i]);
	}
	t = 0;
	build(1, N, 1);
	int x, y;
	for (int i = 0; i < Q; i++)
	{	
		scanf("%d%d", &x, &y);
		cout << query_r(x, y, 1, N, 1) - query_l(x, y, 1, N, 1) << endl;
	}	
	return 0;
}