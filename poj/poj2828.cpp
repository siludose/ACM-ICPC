#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;

int n, ans[1000000];

struct node
{
	int n, val;
} a[1000000];

struct tree
{
	int l, r, n;
} b[1000000];

void init()
{
	int i, j, k;
	for (k = 1; k < n; k <<= 1);
	for (i = k; i < 2 * k; i++)
	{
		b[i].l = b[i].r = i - k + 1;
		b[i].n = 1;//每个叶子节点只能放入一人  
	}
	for (i = k - 1; i > 0; i--)
	{
		b[i].l = b[2 * i].l;
		b[i].r = b[2 * i + 1].r;
		b[i].n = b[2 * i].n + b[2 * i + 1].n;//每个区间是其左右子树所能插入人数的总和  
	}
}

void insert(int i, int x, int m)
{
	if (b[i].l == b[i].r)//找到叶子节点，这个节点存放该人，并且叶子节点能放的人数清0  
	{
		ans[b[i].l] = m;
		b[i].n = 0;
		return;
	}
	if (x <= b[2 * i].n)//其插入的位置若能放入左子树（还能放人），往左子树方向搜，否则走右子树  
		insert(2 * i, x, m);
	else
		insert(2 * i + 1, x - b[2 * i].n, m);
	b[i].n--;//放完后，该节点的人数减一  
}

int main()
{
	int i, j;
	while (~scanf("%d", &n))
	{
		for (i = 1; i <= n; i++)
			scanf("%d%d", &a[i].n, &a[i].val); 
		init();
		for (i = n; i > 0; i--)//逆推  
		{
			insert(1, a[i].n + 1, a[i].val);
		}
		printf("%d", ans[1]);
		for (i = 2; i <= n; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}