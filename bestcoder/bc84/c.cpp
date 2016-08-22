#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define maxn 200100
using namespace std;
ll t,n,L,R;
ll a[maxn];
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&n,&L,&R);
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n);
        ll ans=0;    
        for(int i=n-1;i>=1;i--)
        {
           ll l=a[i]-a[i-1]+1,r=a[i]+a[i-1]-1;
           if(l>R||r<L)continue;
           if(r<R)ans+=R-r;
           R=l-1;
           if(L>R)break;
        }
        if(L<=R)
        {
        	ans+=R-L+1;
		}
        printf("%I64d\n",ans);
    }
    return 0;
}
