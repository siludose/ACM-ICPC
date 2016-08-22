#include<iostream>
using namespace std;
void print_(int n,int *A,int cur)
{
	if(cur==n)
	{
		for(int i=0;i<n;i++)cout<<A[i];
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++){
			int ok=1;
			for(int j=0;i<cur;j++)
				if(A[j]==i)ok=0;
			if(ok){
				A[cur]=i;
				print_(n,A,cur+1);
			}
		}
	}
}
int main()
{
	int n=9;
	int A[10]={1,2,3,4,5,6,7,8,9,10};
	print_(n,A,0);
	return 0;
} 
