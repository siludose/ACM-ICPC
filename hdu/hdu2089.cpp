#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
//#pragma warning(disable:4996)
using namespace std;

int f[10][10];
void init()
{	
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i=1;i<=7;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(j!=4&&!(j==6&&k==2))
				{
					f[i][j]+=f[i-1][k];
				}
			}
		}
	}
}
int solve(int n)
{
	int dight[10];
	int len = 0;
	while (n > 0)
	{
		dight[++len] = n % 10;
		n /= 10;
	}
	dight[len + 1] = 0;
	int ans = 0;
	for (int i = len; i; i--)
	{
		for (int j = 0; j < dight[i]; j++)
		{
			if (j != 4 && !(dight[i + 1] == 6 && j == 2))
			{
				ans += f[i][j];
			}
		}
		if (dight[i] == 4 || (dight[i] == 2 && dight[i + 1] == 6))
		{
			break;
		}
	}
    // for(int i=len;i;i--)
    // {
    //     if (dight[i] == 4 || (dight[i] == 2 && dight[i + 1] == 6))
    //     {
    //         ans--;
    //         break;
    //     }
    // }
	return ans;
}
int main()
{
    init();
	int n, m;
	while(scanf("%d%d",&n,&m))
	{
		if (n + m == 0)
		{
			break;
		}
		else
		{
			printf("%d\n", solve( m+1 ) - solve(n));
		}
	}
	return 0;
}
