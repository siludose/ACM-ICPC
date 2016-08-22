#include<iostream>
#define ll long long
using namespace std;
int main()
{

	int m,n;
	while(cin>>m>>n)
	{
		ll ans=1;
		ll div; 
		for(int i=1;i<=m;i++)
		{
			ans*=i;
			if(i==n)
			{
				div=ans;
			}
		}
		printf("%lld %lld\n",ans,div);
		printf("%lld\n",ans/div);
	}
	
	return 0;
}
