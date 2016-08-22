#include<iostream>
using namespace std;
long long k,n,w;
int main()
{
    scanf("%lld%lld%lld",&k,&n,&w);
    long long temp=(1+w)*w*k/(2.0);
    if(temp<=n)
	{
		printf("%d",0);
	}
    else
    {
    	printf("%d",temp-n);
	}
    
    return 0;
}
