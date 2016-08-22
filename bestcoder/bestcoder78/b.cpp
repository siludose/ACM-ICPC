#include<iostream>
using namespace std;
#define mod 100000007
int t,n,a;
int sum;
bool num[1010];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			num[a]=true;
			sum+=a;
		}	
//		for(int i=0;i<1<<(n-1);i++)
//		{
//			sum=(((sum+sum)%mod)+mod)%mod;
//		}
		for(int i=1;i<=1000;i++)
		{
			if(num[i])
			{
				int temp=i;
				int count=0;
				while(temp<=1000)
				{
					temp+=i;
					if(num[temp])
					{
						count++;
					}
				}
				sum=(((sum+pow(i*1.0,count)%mod)+mod)%mod;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
