#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
//#pragma warning(dsiable:4996)
using namespace std;
int t;int n;
int x,a[20];
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
    	int sum=0;
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]);
    		sum+=a[i];
		}
		sort(a+1,a+n+1);
		int l=1,r=n;
		int ans=0;
		while(1)
		{
			if(l!=r&&((sum-2)>=(ans+2)))
			{
				sum-=2;
				ans+=2;
				
				a[l]--;
				if(a[l]==0)
					l++;
					
				a[r]--;
				if(a[r]==0)
					r--;
			}
			else if((sum-ans>=2))
			{
				ans++;
				break;
			}
			else
			{
				break;
			}
			
		}
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
