#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,l[100010];
int main()
{
	scanf("%d",&n);
	ll sum=0;
	int maxx=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
		sum+=l[i];
		maxx=max(maxx,l[i]);
	}
	sum-=maxx;
	sum=maxx-sum+1;
	if(sum>0)
	{
		cout<<sum<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}
