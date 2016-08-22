#include<iostream>
#include<string.h>
using namespace std;
#define ll long long
ll deng[50];
int main()
{
	int t,m;ll n;
	scanf("%d",&t);
	while(t--)
	{
		memset(deng,0,sizeof(deng));
		scanf("%d %I64d",&m,&n);
		ll temp; 
		for(int i=m;i>=1;i--)
		{
			deng[i]=n%3;
			n/=3;
		}
		for(int i=1;i<=m;i++)
		{
			if(deng[i]==0)
			{
				cout<<'R';
			}
			else if(deng[i]==1)
			{
				cout<<'G';
			}
			else
			{
				cout<<'B';
			}
		}
		cout<<endl;
	}
	return 0;	
} 
