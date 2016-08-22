#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
bool flag;
int sum;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
    	flag=true;sum=0;
    	if(n==1)
    	{
    		scanf("%d",&k);
    		if(k==0)
    			flag=0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&k);
				if(k==0)
					sum++;
			}
			if(sum!=1)
				flag=0;
		}
        if(flag)
        {
        	printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
    }
    return 0;
}
