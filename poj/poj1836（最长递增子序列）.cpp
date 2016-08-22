#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
//#pragma warning(disable:4996)
using namespace std;
int n;
int main(int i,int j)
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	double *high=new double[n+1];
	int *up=new int[n+1];
	int *down = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		up[i] = down[i] = 1;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&high[i]);
	}
	for(int i=0;i<n;i++)
	{	
		for(int j=i+1;j<n;j++)
		{
			if(high[j]>high[i])
			{
				up[j]=max(up[i]+1,up[j]);
			}
		}
	}
	for (int i = n-1; i >= 0 ; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (high[j] > high[i])
			{
				down[j] = max(down[i] + 1, down[j]);
			}
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << up[i] << " " << down[i] << endl;
	//}
	int res = 0;
	for(int i=0;i<n;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			res = max(res, up[i] + down[j]);
		}
	}
	cout <<n- res << endl;
	delete high;
	delete up;
	return 0;
}
