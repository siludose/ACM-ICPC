#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define maxn 110
int A[maxn];
void print_subset(int n,int *A,int cur)
{
	for(int i=1;i<cur;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	int s=cur?A[cur-1]+1:0;
	for(int i=s;i<n;i++)
	{
		A[cur]=i;
		print_subset(n,A,cur+1);
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		print_subset(n+1,A,1);
	}
	return 0;
}
