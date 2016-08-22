#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define maxn 110
int B[maxn];
void print_subset(int n,int *B,int cur)
{
	if(cur==n)
	{
		for(int i=0;i<cur;i++)
		{
			if(B[i])
			{
				printf("%d ",i);
			}
		}
		printf("\n");
		return;
	}
	B[cur]=1;
	print_subset(n,B,cur+1);
	B[cur]=0;
	print_subset(n,B,cur+1);
}
int main()
{
	int n;
	while(cin>>n)
	{
		print_subset(n+1,B,1);
	}
	return 0;
}
