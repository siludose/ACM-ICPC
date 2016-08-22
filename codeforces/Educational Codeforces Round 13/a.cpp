#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        printf("%d\n",(n/k+1)*k);
    }
    return 0;
}