#include <iostream>
using namespace std;
const int MAX_N=1000;
int n,a[MAX_N];

struct node
{
	int l,r;
	int min;
}aa[MAX_N*2+5];
int  build(int i,int l,int r)
{
	aa[i].l=a[l];
	aa[i].r=a[r];
	if (l==r)
	{
		aa[i].min=a[l];
		return a[l];
	}
	else
	{
		int mid=(l+r)/2;
		aa[i].min=min(build(i*2+1,mid+1,r),build(i*2,l,mid));
	}
	return aa[i].min;
}
int find_min(int i,int l,int r)
{

}
int main()
{
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(1,0,n-1);
	int n_=2;
	while(n_<=n)
	{
		n_*=2;
	}
	for (int i=1;i<n_;i++)
	{
		printf("%d %d %d\n",aa[i].l,aa[i].r,aa[i].min);
	}
	return 0;
}