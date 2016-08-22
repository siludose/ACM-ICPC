#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        if(n%3==0)
        {
            printf("Cici\n");
        }
        else
        {
            printf("Kiki\n");
        }
    }
    return 0;
}