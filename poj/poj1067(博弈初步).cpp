#include<iostream>
#include<algorithm>
#include<cstdio>
#include<math.h>
using namespace std;
int a,b;
int main()
{
    while(~scanf("%d%d",&a,&b))
    {
        int num=abs(a-b);
        int k=double(num*(1+sqrt(5.0))/2);
        a=a<b?a:b;
        printf("%d\n",a!=k);
    }
    return 0;
}
