#include <iostream>
using namespace std;
int Max(int a, int b)
{
	return a>b ? a : b;
}
int MEMOIZED_CUT_ROD_AUX(int p[], int n, int r[])
{
	static int q;
	if (r[n] >= 0)
	{//保存已求过的值。
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = -0x7fffffff;
		for (int i = 0; i<n; i++)
		{
			q = Max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n - i - 1, r));
		}
	}
	r[n] = q;
	return q;
}
int MEMOIZED_CUT_ROD(int p[], int n)
{//方法①自顶向下的动态规划方案
	int *r = new int[n];
	for (int i = 0; i<n; i++)
	{
		r[i] = -0x7fffffff;
	}
	return MEMOIZED_CUT_ROD_AUX(p, n, r);
}
int BOTTOM_UP_CUT_ROD(int p[], int n)
{//方法②自底向下的动态规划方案
	int *r = new int[n];
	r[0] = 0;
	for (int j = 0; j<n; j++)
	{
		int q = -0x7fffffff;
		//int q=p[j+1];
		for (int i = 0; i <= j; i++)
		{
			q = Max(q, p[i] + r[j - i]);
		}
		r[j + 1] = q;
		for (int i = 0; i <= j + 1; i++)
		{
			cout << r[i]<<" ";
		}
		cout << endl;
		
	}
	return r[n];
}
void main()
{
	const int n = 10;
	int p[10] = { 1,5,8,9,10,17,17,20,24,30 };
	cout << MEMOIZED_CUT_ROD(p, 9) << endl;
	cout << BOTTOM_UP_CUT_ROD(p, 9) << endl;
}