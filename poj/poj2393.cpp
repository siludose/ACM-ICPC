#include <iostream>
#include<cmath>
using namespace std;
const int maxn=10001;
#define ll long long
int n,s;
int c[maxn],y[maxn];
ll solve()
{
	ll spend=0;
	for (int i=1;i<n;i++)
	{
		c[i]=min(c[i-1]+s,c[i]);
	}
	for (int i=0;i<n;i++)
	{
		spend+=c[i]*y[i];
	}
	return spend;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		cin>>c[i]>>y[i];
	}
	cout<<solve();
	return 0;
}