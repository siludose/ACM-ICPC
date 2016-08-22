#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1))
        {
            printf("first\n");
        }
        else
        {
            printf("second\n");
        }
    }
    return 0;
}