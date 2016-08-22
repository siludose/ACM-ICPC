#include<iostream>
#include<cstdio>
using namespace std;
__int64 a,b,n,x;
const int mod=1000000007;
__int64 inv(__int64 a,__int64 m)
{
	if(a==1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}
__int64 result(__int64 a,__int64 b)
{
    __int64 d,t;

    d=1;
    t=a;
    while (b>0)
    {
        if (b%2==1)
            d=(d*t)%mod;
        b/=2;
        t=(t*t)%mod;
    }

    return d;
}
int main()
{
    while(~scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&x))
    {
    	if(a==1)
    	{
    		printf("%I64d\n",(b*(n%mod)%mod+x)%mod);continue;
		}
        __int64 res=result(a,n);
        printf("%I64d\n",(res*x%mod+((res-1)*inv(a-1,mod)%mod)*b%mod)%mod);
    }
    return 0;
}
