#include<iostream>
using namespace std;
int n,m,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if((m%n==0)||(n%m==0))
		{
			if(m%n==0)
			{
				printf("%d\n",m/n);
			}
			else
			{
				printf("%d\n",n/m);
			}
			continue;
		}				
		int count=0;	
		while(1)
		{		
			
			if(m>n)
			{
				int temp=m;
				m=n;
				n=temp;
			}
			if(n%m==0)
			{
				printf("%d\n",(n/m)+count);
				break;
			}
			count+=1;
			int temp=m;
			m=n-m;
			n=temp;
		}
	}
	return 0;
}
