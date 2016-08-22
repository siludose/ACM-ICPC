#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int MAXN = 110000;
#define ll long long
ll a[MAXN];
int main()
{
    //freopen("input.txt","r",stdin);
    int t,n,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        int la,ra,lb,rb;
        while(q--)
        {
            scanf("%d%d%d%d",&la,&ra,&lb,&rb);
            if(la>lb)
            {
            	swap(la,lb);
            	swap(ra,rb);
			}
			if(ra<lb)
			{
				int lena=ra-la+1;
	            int lenb=rb-lb+1;
	            int mi=(lena+lenb)/2+1;
	            int index=1;
	            if((lena+lenb)%2==1)
	            {
	                if(mi<=lena)
	                {
	                    index=la+mi-1;
	                }
	                else
	                {
	                    index=lb+(mi-lena)-1;
	                }
	                printf("%.1lf\n",a[index]*1.0);
	            }
	            else
	            {
	                int mii=mi-1;
	                int indexx = 1;
	                if(mi<=lena)
	                {
	                    index=la+mi-1;
	                }
	                else
	                {
	                    index=lb+(mi-lena)-1;
	                }
	                if(mii<=lena)
	                {
	                    indexx=la+mii-1;
	                }
	                else
	                {
	                    indexx=lb+(mii-lena)-1;
	                }
	                printf("%.1lf\n",(a[index]+a[indexx])/2.0);
	            }
			}
            else
            {
            	int l1=la;
            	int l2=lb;
            	int l3=min(ra,rb);
            	int l4=max(ra,rb);
            	int mi=(ra-la+rb-lb+2)/2+1;
            	int index = 1;
            	if((ra-la+rb-lb+2)%2==1)
            	{
            		if(mi<=(l2-l1))
            			index=l1+mi-1;
					else if(mi<=(  (l2-l1)+(l3-l2+1)*2) )
					{
						mi=mi-(l2-l1);	
						mi=(mi+1)/2;
						index=l2+mi-1;					
					}	
					else
					{
						mi=mi-(  (l2-l1)+(l3-l2+1)*2);
						index=l3+mi;
					}
					printf("%.1lf\n",a[index]*1.0);
				}
				else
				{
					int l1=la;
	            	int l2=lb;
	            	int l3=min(ra,rb);
	            	int l4=max(ra,rb);
	            	int mi=(ra-la+rb-lb+2)/2+1;
	            	int mii=mi-1;
	            	int index = 1,indexx = 1;
	            	if(mi<=(l2-l1))
            			index=l1+mi-1;
					else if(mi<=(  (l2-l1)+(l3-l2+1)*2) )
					{
						mi=mi-(l2-l1);	
						mi = (mi +1)/ 2;
						index=l2+mi-1;					
					}	
					else
					{
						mi=mi-(  (l2-l1)+(l3-l2+1)*2);
						index=l3+mi;
					}
					if(mii<=(l2-l1))
            			indexx=l1+mii-1;
					else if(mii<=(  (l2-l1)+(l3-l2+1)*2) )
					{
						mii=mii-(l2-l1);	
						mii=(mii+1)/2;
						indexx=l2+mii-1;					
					}	
					else
					{
						mii=mii-(  (l2-l1)+(l3-l2+1)*2);
						indexx=l3+mii;
					}
					printf("%.1lf\n",(a[index]+a[indexx])/2.0);
				}
			}
        }
    }
    return 0;
}
