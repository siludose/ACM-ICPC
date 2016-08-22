#include<iostream>
#include<cmath>
#include<cstdio>
#define maxn 32000
using namespace std;
int a1[maxn];
__int64 a2[maxn];
int num[150000];
int t,number;
int main()
{
	a1[0]=0;
	a1[1]=1;
	for(int i=2;i<maxn;i++)
	{
		a1[i]=a1[i-1]+1+(int)log10(1.0*i);//mark！
	}
	for(int i=1;i<maxn;i++)
	{
		a2[i]=a2[i-1]+a1[i];//mark again
	}
	int k=1;
	for(int i=1;i<31300;i++)
	{
		char str[20];
		
		str[0]='0';
		int ti=i;
		int len=0;
		while(ti)
		{
			str[len]=ti%10+'0';
			ti/=10;
			len++;
		}
		while(len--)
		{
			num[k]=str[len]-'0';
			k++;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&number);
		int i=1;
		for(;i<32300;i++)
		{
			if(number<=a2[i])
			{
				break;
			}
		}
		if(number==a2[i])
		{
			cout<<i<<endl;
		}
		else
		{
			cout<<num[number-a2[i-1]]<<endl;
		}
	}
	return 0;
}
