#include<iostream>
#include<cstdio>
using namespace std;
int t,s,x;
int main()
{
    while(~scanf("%d%d%d",&t,&s,&x))
    {
        if(x==t)
        {
            printf("Yes\n");continue;
        }
        x-=t;
        if(x>0)
        {
            int num1=x/s;int num2=x%s;
            if(num1>=1&&num2<=1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
