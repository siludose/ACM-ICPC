#include "stdio.h"
#include "iostream"
#include "math.h"
#include "malloc.h"
#include "string.h"
using namespace std;

//大整数乘法 http://acm.swust.edu.cn/oj/problem/447/
/*             输入有三行
               第一行是大整数位数
               第一个大整数
			   第二个大整数                */

#define INF 0xFFFFFF
#define CC(a, b, c)  ((a+b+c)/10)
#define MM(a, b, c)  ((a+b+c)%10)

#define MultCC(a, b, c) ((a*b+c)/10)
#define MultMM(a, b, c) ((a*b+c)%10)

#define a1 0
#define a2 1
#define sum 2

int a[3][10003] = {0};

//a + b -> c     m -> a   n -> b
void ADDNUM(int a[], int b[], int c[], int m, int n)
{
	int C;
	c[0] = MM(a[0], b[0], 0);
	C = CC(a[0], b[0], 0);

	int i = 0;
	int num = min(n, m);
	for (i = 1; i < num; i++)
	{
		c[i] = MM(a[i], b[i], C);
		C = CC(a[i], b[i], C);
	}
	num = max(n, m);
	int h = 0;
	if (num == m)
	{
		h = a1;
	
		for (i; i < num; i++)
		{
			c[i] = MM(a[i], 0, C);
			C = CC(a[i], 0, C);
		}
		if (C > 0)
			c[num] = C;
	
	}
	else 
	{
		h = a2;

		for (i; i < num; i++)
		{
			c[i] = MM(b[i], 0, C);
			C = CC(b[i], 0, C);
		}
		if (C > 0)
			c[num] = C;
	}

}

//移位 即 将数组内数字扩大10倍
void Translation(int a[], int n)
{
	for (int i = n; i > 0; i--)
	{
		a[i] = a[i-1];
	}
	a[0] = 0;
}

//逐位乘以 b
void MultNum(int a[], int b, int c[], int m)
{
	int C;
	c[0] = MultMM(a[0], b, 0);
	C = MultCC(a[0], b, 0);

	int i = 0;
	int num = m;
	for (i = 1; i < num; i++)
	{
		c[i] = MultMM(a[i], b, C);
		C = MultCC(a[i], b, C);
	}
	if (C > 0)
		c[num] = C;

	//if (c[num] > 0)
	//	cout << c[i];

	//for (i = 0; i < num; i++)
	//{
	//	cout << c[num-i-1];
	//}
	//cout << endl;
}


int main()
{
	int m, n, C;
	/*cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		//低位存入低位
		cin >> a[a1][m-i-1];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[a2][n-i-1];
	}//*/

	cin >> m;
	n = m;
	char str[103] = {};
	cin >> str;
	for (int i = n-1; i >= 0; i--)
	{
		//低位存入低位
		a[a1][n-i-1] = str[i] - '0';
	}
	cin >> str;
	for (int i = n-1; i >= 0; i--)
	{
		//低位存入低位
		a[a2][n-i-1] = str[i] - '0';
	}
	
	//ADDNUM(a[a1], a[a2], a[sum], m, n);
	int count = n;
	int length = m;
	while (count--)
	{
		for (int i = 0; i < a[a2][count]; i++)
		{
			int temp[10003];
			ADDNUM(a[a1], a[sum], temp, m, m+n);
			for (int j = 0; j < m+n; j++)
			{
				a[sum][j] = temp[j];
			}
		}
		if (count)
			Translation(a[sum], m+n);

		/*if (a[sum][length] > 0)
			cout << a[sum][length];
		for (int i = 0; i < length; i++)
		{
			cout << a[sum][length-i-1];
		}
		cout << endl;*/
	}




	int num = m + n;
	bool firstnum = false;
	int i = 0;
	while (!a[sum][num-i-1])
	{
		i++;
	}
	for (i; i < num; i++)
	{
			cout << a[sum][num-i-1];
	}
	cout << endl;
	return 0;
}
/*
20 20
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
5 3
7 5 6 7 8
7 0 0
2 2
1 6
1 6
10
1111111111
1111111111
  */