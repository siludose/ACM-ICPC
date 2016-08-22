/*
这份代码不是我写的，来自网上某个大神
因为觉得实在写的太棒了，根本不想改动
从它的代码中，我很容易的就理解了（nlogn）计算最长上升子序列
他对最长上升子序列算法的灵活运用也让我佩服不已
这给我一个提醒，很多算法真的不能只是会用
如果不理解就觉得自己会用这很有可能只是假象
希望以后能够去理解更多算法，而不仅仅是看起来会用
感谢上帝，这同时也是一道很棒的题目呀！
*/
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;

const int MAXN = 1e5 + 111;

int a[MAXN], arr[MAXN], b[MAXN], dp[MAXN]; // arr:LIS  dp:以这个开头的最长上升子序列  

int main()
{
	int t, kase;
	for (int kase = scanf("%d", &t); kase <= t; ++kase)
	{
		int n, l;
		printf("Case #%d: ", kase);
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			b[i] = -a[i]; // 取相反数，这样可以从后往前LIS  
		}
		int x;
		memset(arr, 0x7f, sizeof arr);
		for (int i = n - 1; i >= l; --i)
		{
			x = lower_bound(arr, arr + n, b[i]) - arr;
			arr[x] = b[i];
			dp[i] = x + 1; // 长度等于下标 + 1  
		}

		int ans = 0, mxlen = 0;
		memset(arr, 0x7f, sizeof arr);
		for (int i = l; i < n; ++i)
		{
			x = lower_bound(arr, arr + n, a[i]) - arr; //从左边的LIS查找  
			ans = max(ans, x + 1 + dp[i] - 1); // 之所以减一是因为我们从左边查找的是大于等于的  
			x = lower_bound(arr, arr + n, a[i - l]) - arr; // 左边更新LIS  
			arr[x] = a[i - l];
			mxlen = max(mxlen, x + 1);
		}
		ans = max(ans, mxlen); //最后要比较下滑动窗口滑动到最后的情况  
		printf("%d\n", ans);
	}
	return 0;
}
