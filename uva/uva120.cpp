#include <iostream>
#include <cstdio>
#include<cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int kk[35];
int jj[35];
void exchange(int a[],int l,int r)
{
	while (r-l>0)
	{
		int temp = a[l];
		a[l] = a[r];
		a[r] = temp;
		l++;
		r--;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	while (scanf("%d",&kk[0])!=EOF)
	{
		printf("%d", kk[0]);
		jj[0] = kk[0];
		int n = 0;
		while (getchar()!='\n')
		{
			scanf("%d", &kk[++n]);
			jj[n] = kk[n];
			printf("%d", kk[n]);
		}
		printf("\n");
		sort(jj,jj+n+1);
		for (int i = n; i >= 0; i--)
		{
			if (jj[i]==kk[i])
			{
				continue;
			}
			else
			{
				int j;
				
				for ( j= i; i >= 0;i--)				
					if (kk[j]==jj[i])					
						break;
				
				if (j != 0)
				{
					exchange(kk, 0, j);
					printf("%d ", n - j + 1);
				}			
				
				if (i != 0)
				{
					exchange(kk, 0, i);
					printf("%d ", n - i + 1);
				}										
			}
		}
		printf("%d\n", 0);
	}
	return 0;
}