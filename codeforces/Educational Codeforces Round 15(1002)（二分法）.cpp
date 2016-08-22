#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
#define maxn 100100
int n,a[maxn];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
    	long long ans=0;
    	sort(a+1,a+1+n);
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=30;j>=0;j--){
				int num=1<<j;
				if(num<a[i])break;
				int tmp=num-a[i];
				int pos1=lower_bound(a+1,a+1+n,tmp)-a;
				int pos2=upper_bound(a+1,a+1+n,tmp)-a;
				if(a[pos1]==tmp){
					ans+=pos2-pos1;
					if(tmp==a[i])ans--;
				}
			}
		}
        printf("%I64d\n",ans/2);
    }
    return 0;
}
