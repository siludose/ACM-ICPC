#include<iostream>
#include<algorithm>
//#pragma warning(disable:4996)
using namespace std;
const int maxn = 350;
int row;
int c[maxn][maxn];
int sc[maxn][maxn];
int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &row);
	scanf("%d", &c[0][0]);
	for (int i=1; i < row; i++)
	{
		int j = 0;
		for (; j <= i; j++)
		{
			scanf("%d",&c[i][j]);
		}		
	}
	sc[0][0] = c[0][0];
	for (int i = 1; i < row; i++)
	{
		sc[i][0] = sc[i - 1][0] + c[i][0];
		sc[i][i] = sc[i - 1][i-1] + c[i][i];
	}



	for (int i=1; i < row; i++)
	{
		for (int j = 1; j < i; j++)
		{
			sc[i][j] = max(sc[i - 1][j - 1], sc[i - 1][j]) + c[i][j];
		}
	}
	int max_i = 0;
	for (int i = 1; i < row; i++)
	{
		if (sc[row-1][i]>sc[row-1][max_i])
		{
			max_i = i;
		}
	}
	printf("%d", sc[row-1][max_i]);
	return 0;
}