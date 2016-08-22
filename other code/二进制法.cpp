#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define maxn 110
int B[maxn];
void print_subset(int n,int s)
{
	for(int i=0;i<=n;i++)
	{
		if(s&(1<<i))
			printf("%d ",i+1);
	}
	printf("\n");
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<(1<<n);i++)
		{
			print_subset(n+1,i);
		}	
	}
	return 0;
}
