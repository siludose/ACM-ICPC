#include<iostream>
using namespace std;
#define maxn 1010
int n;
int a[maxn];
int b[maxn]; 
bool judge(int a,int b)
{
	while(1)
	{
		if(a%b==0)
		{
			return false;
		}
		if(a%b==1)
		{
			return true;
		}
		int c=a%b;
		a=b;b=c;
	}
} 
int main()
{
	scanf("%d",&n);
	int res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==1||a[i-1]==1)
		{
			continue;
		}
		if(!judge(a[i],a[i-1]))
		{
			int c=a[i-1]+1;
			while(1)
			{
				if(judge(c,a[i-1])&&judge(a[i],c))
				{
					b[i]=c;
					break;
				}
				c++;
			}
			res++;
		}
	}
	cout<<res<<endl;
	for(int i=0;i<n;i++)
	{
		if(b[i]>0)
		{
			cout<<b[i]<<" ";
		}
		cout<<a[i];
		if(i!=n-1)
		{
			cout<<" ";
		}
	}
	return 0;
}
