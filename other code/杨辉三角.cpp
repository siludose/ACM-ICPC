#include<iostream>
using namespace std;
const int maxn=1000;
int a[maxn];
int b[maxn];
int main()
{
	int n;
	cin>>n;
	a[1]=1;

	for(int i=1;i<=n;i++)
	{

		for(int j=1;j<=i;j++)
		{
			b[j] = a[j - 1] + a[j];
			cout<<b[j]<<" ";
		}
		cout<<endl;
		for (int j = 1; j <= i;j++)
		{
			a[j] = b[j];
		}
	}
}
