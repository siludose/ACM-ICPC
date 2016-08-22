#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=20;
int n,c;
int ans=0;
struct Money
{
	int v;
	int num;
}m[maxn];

bool cmp(const Money &a,const Money &b)
{
	return a.v>b.v;
}
int add(int i)
{
	for (int k=n-1;k>=i;k--)
	{
		if (m[k].num!=0)
		{
			m[k].num--;
			return m[k].v;
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	
	cin>>n>>c;
	for (int i=0;i<n;i++)
	{
		cin>>m[i].v>>m[i].num;
	}
	sort(m,m+n,cmp);
	int i;
	for (i=0;i<n;i++)
	{
		if (m[i].v>=c)
		{
			ans+=m[i].num;
			m[i].num=0;
		}
		else
			break;
	}
	for (;i<n;i++)
	{	
		if (m[i].num==0)
		{
			continue;
		}
		while(m[i].num!=0)
		{
			m[i].num--;
			int v_add=add(i);
			int sum=m[i].v+v_add;
			while (sum<c&&v_add)
			{
				v_add=add(i);
				sum+=v_add;
			}
			if (!v_add)
			{
				cout<<ans;
				return 0;
			}
			else
			{
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}