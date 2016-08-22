#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 100100
int t,m,x;
int a[maxn], ans[maxn];
int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &m);
		int cnt = 0, n = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &x);
			if (!x)cnt++;
			else a[++n] = x - cnt;
		}
		if (!n)
		{
			printf("Case #%d: %d\n", cas, m);
			continue;
		}
		ans[1] = a[1];
		int len = 1;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] > ans[len])ans[++len] = a[i];
			else
			{
				int pos = lower_bound(ans + 1, ans + len, a[i]) - ans;
				ans[pos] = a[i];
			}
		}
		printf("Case #%d: %d\n", cas, len + cnt);
	}
    return 0;
}
