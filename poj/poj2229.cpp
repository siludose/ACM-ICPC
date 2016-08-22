//#pragma warning(disable:4996)
#include<iostream>
#define maxn 1000000+50
int N;
int c[maxn];
int main()
{
	scanf("%d", &N);
	c[1] = 1;
	c[2] = 2;
	if (N > 2)
	{
		for (int i = 3; i <= N; i++)
		{
			c[i] = c[i - 2] + c[i / 2];
			c[i] = c[i] % 1000000000;
		}
	}
	printf("%d", c[N]);
	return 0;
}