/*
��ݴ��벻����д�ģ���������ĳ������
��Ϊ����ʵ��д��̫���ˣ���������Ķ�
�����Ĵ����У��Һ����׵ľ�����ˣ�nlogn�����������������
����������������㷨���������Ҳ�����������
�����һ�����ѣ��ܶ��㷨��Ĳ���ֻ�ǻ���
��������;����Լ���������п���ֻ�Ǽ���
ϣ���Ժ��ܹ�ȥ�������㷨�����������ǿ���������
��л�ϵۣ���ͬʱҲ��һ���ܰ�����Ŀѽ��
*/
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;

const int MAXN = 1e5 + 111;

int a[MAXN], arr[MAXN], b[MAXN], dp[MAXN]; // arr:LIS  dp:�������ͷ�������������  

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
			b[i] = -a[i]; // ȡ�෴�����������ԴӺ���ǰLIS  
		}
		int x;
		memset(arr, 0x7f, sizeof arr);
		for (int i = n - 1; i >= l; --i)
		{
			x = lower_bound(arr, arr + n, b[i]) - arr;
			arr[x] = b[i];
			dp[i] = x + 1; // ���ȵ����±� + 1  
		}

		int ans = 0, mxlen = 0;
		memset(arr, 0x7f, sizeof arr);
		for (int i = l; i < n; ++i)
		{
			x = lower_bound(arr, arr + n, a[i]) - arr; //����ߵ�LIS����  
			ans = max(ans, x + 1 + dp[i] - 1); // ֮���Լ�һ����Ϊ���Ǵ���߲��ҵ��Ǵ��ڵ��ڵ�  
			x = lower_bound(arr, arr + n, a[i - l]) - arr; // ��߸���LIS  
			arr[x] = a[i - l];
			mxlen = max(mxlen, x + 1);
		}
		ans = max(ans, mxlen); //���Ҫ�Ƚ��»������ڻ������������  
		printf("%d\n", ans);
	}
	return 0;
}
