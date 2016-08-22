#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define maxn 31
int t,n,m,size,max_size;
int a[maxn];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
    	memset(a,0,sizeof(a));size=0;max_size=0;
        scanf("%d%d",&n,&m);
        for(int i=maxn-1;i>=0;i--)
        {
        	if(n&(1<<i))
        	{
        		a[i]=1;size++;
        		if(max_size==0)
        		{
        			max_size=i;
				}
			}		
		}
		if(max_size<=m)
		{
			printf("%d\n",size);
		}
		else
		{
			int sum=0;
			for(int i=m;i<=max_size;i++)
			{
				if(a[i])
				{
					sum+=1<<(i-m);
					size--;
				}
			}
			printf("%d\n",sum+size);
		}
    }
    return 0;
}
