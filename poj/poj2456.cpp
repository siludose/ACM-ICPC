#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=100005;
int x[MAX_N];
int n,m;
bool C(int d) 
{
	int last=0;
	for (int i=1;i<m;i++)
	{
		int crt=last+1;
		while(crt<n&&x[crt]-x[last]<d){
			crt++;
		}
		if(crt==n) return false;
		last=crt;
	}
	return true;
}
void solve()
{
	sort(x,x+n);
	int lb=0,ub=0x7f7f7f7f;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if (C(mid)) 
			lb=mid;
		else
			ub=mid;
	}
	printf("%d",lb);
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	solve();
	return 0;
}