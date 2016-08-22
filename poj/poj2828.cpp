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
		b[i].n = 1;//ÿ��Ҷ�ӽڵ�ֻ�ܷ���һ��  
	}
	for (i = k - 1; i > 0; i--)
	{
		b[i].l = b[2 * i].l;
		b[i].r = b[2 * i + 1].r;
		b[i].n = b[2 * i].n + b[2 * i + 1].n;//ÿ���������������������ܲ����������ܺ�  
	}
}

void insert(int i, int x, int m)
{
	if (b[i].l == b[i].r)//�ҵ�Ҷ�ӽڵ㣬����ڵ��Ÿ��ˣ�����Ҷ�ӽڵ��ܷŵ�������0  
	{
		ans[b[i].l] = m;
		b[i].n = 0;
		return;
	}
	if (x <= b[2 * i].n)//������λ�����ܷ��������������ܷ��ˣ����������������ѣ�������������  
		insert(2 * i, x, m);
	else
		insert(2 * i + 1, x - b[2 * i].n, m);
	b[i].n--;//����󣬸ýڵ��������һ  
}

int main()
{
	int i, j;
	while (~scanf("%d", &n))
	{
		for (i = 1; i <= n; i++)
			scanf("%d%d", &a[i].n, &a[i].val); 
		init();
		for (i = n; i > 0; i--)//����  
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