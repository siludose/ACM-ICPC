#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 10005
#define mod 998244353
#define ll long long
using namespace std;
int t,n;
int big[maxn],small[maxn];
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&small[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&big[i]);
        int mi,ma;bool flag=false;ll sum=1;
        int xia=small[0],shang=big[0];
        if(xia>shang)
        {
            printf("0\n");continue;
        }
        for(int i=1;i<n;i++)
        {
            if(small[i]<xia)
            {
                xia=small[i];
                mi=0;
            }
            else
            {
                mi=shang+1;
            }
            if(big[i]>shang)
            {
                shang=big[i];
                ma=0;
            }
            else
            {
                ma=xia-1;
            }
            if(mi&&ma)
            {
                if(xia>shang)
                {
                    printf("0\n");flag=true;break;
                }
                else
                {
                    sum=sum*(shang-xia+1)%mod;
                }
            }
        }
        if(flag)
        {
            printf("0\n");
        }
        else
        {
        	printf("%d\n",sum);
		}
    }
    return 0;
}
