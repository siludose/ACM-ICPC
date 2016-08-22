#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h> 
#pragma warning(disable:4996)
using namespace std;
#define ll __int64
ll a,b,c,n;
int main()
{
    while(scanf("%I64d",&a)!=EOF)
    {
        if(a==1)
        {
            printf("%d\n",-1);continue;
        }
        if(a%2==1){
            n=(a-1)/2;
            b=2*n*n+2*n;
            c=2*n*n+2*n+1;
        }
        else
        {
            n=a/2;
            b=n*n-1;
            c=n*n+1;
        }
        printf("%I64d %I64d\n",b,c);
    }
    return 0;
}
